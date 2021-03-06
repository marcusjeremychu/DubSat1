#!/usr/bin/env python3

# Copyright (c) 2013, Eduard Broecker
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that
# the following conditions are met:
#
#    Redistributions of source code must retain the above copyright notice, this list of conditions and the
#    following disclaimer.
#    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
#    following disclaimer in the documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
# PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
# DAMAGE.

from __future__ import print_function
from __future__ import absolute_import

# from .log import setup_logger, set_log_level
#logger = setup_logger('root')
import sys
import os
sys.path.append('..')
import canmatrix.formats
import canmatrix.canmatrix as cm
import canmatrix.copy as cmcp

def toPyObject(infile, outfileName, **options):
    dbs = {}
    dbs = canmatrix.formats.loadp(infile, **options)
    outdbs = {}
    for name in dbs:
        db = None
        if db is None:
            db = dbs[name]
        outdbs[name] = db
    return outdbs['']

def createCHeaderBackup(candb, cFileName):
    cFile = open(cFileName, "w")
    cFile.write("#ifndef CANDB_HEADER\n#define CANDB_HEADER\n\n")
    cFile.write("#include <stdint.h>\n\n")
    for frame in candb.frames:
        cFile.write("typedef struct {\n")
        for sig in frame:
            if sig.is_signed:
                cFile.write("\tint")
            else:
                cFile.write("\tuint")
            if sig.signalsize == 8:
                cFile.write("8_t ")
            elif sig.signalsize == 16:
                cFile.write("16_t ")
            elif sig.signalsize == 32:
                cFile.write("32_t ")
            else:
                cFile.write("64_t ")
            cFile.write(sig.name + ";\n")
        cFile.write("} " + frame.name + ";\n\n")
    cFile.write("\n#endif")
    cFile.close()

def getSignalSize(sig, frame, floatList):
    if sig.is_signed and sig.signalsize != 8 and sig.signalsize != 16 and sig.signalsize != 32 and sig.signalsize != 64:
        print("Warning: "+ sig.name +" is signed and not a standard width. This may not work right.")
    if ((frame.id, sig.name, 1) in floatList):
        return "float"
    elif ((frame.id, sig.name, 2) in floatList):
        return "double"
    elif sig.min >= 0 and sig.max <= 2 ** 8 - 1:
        return "uint8_t"
    elif sig.min >= 0 and sig.max <=  2 ** 16 - 1:
        return "uint16_t"
    elif sig.min >= 0 and sig.max <=  2 ** 32 - 1:
        return "uint32_t"
    elif sig.min >= 0 and sig.max <=  2 ** 64 - 1:
        return "uint64_t"
    elif sig.min >= - (2 ** (8-1)) and sig.max <=  2 ** (8-1) - 1:
        return "int8_t"
    elif sig.min >= - (2 ** (16-1)) and sig.max <=  2 ** (16-1) - 1:
        return "int16_t"
    elif sig.min >= - (2 ** (32-1)) and sig.max <=  2 ** (32-1) - 1:
        return "int32_t"
    elif sig.min >= - (2 ** (64-1)) and sig.max <=  2 ** (64-1) - 1:
        return "int64_t"
    else:
        print("Warning: " + sig.name + " type unknown. Using uint8_t instead.")
        return "uint8_t"

def createCHeader(candb, cFileName, floatList):
    cFile = open(cFileName, "w")
    cFile.write('''/*
 * canwrap.h
 *
 *  Created on: Aug 14, 2017
 *      Author: emoryeng
 */

#include <inttypes.h>

#ifndef DSBASE_INTERFACES_CANWRAP_H_
#define DSBASE_INTERFACES_CANWRAP_H_

#define PARAM_ADCS_STATUS_VELOCITY_RPM 0x4201;


// BEGIN GENERATOR MACROS

''')
    # Add macros for packet IDs for filter purposes.
    for frame in candb.frames:
        cFile.write("#define CAN_ID_" + frame.name.upper() + " " + (str(frame.id) if frame.id != 2147483648 else "0") + "\n")
    # Add macros for ENUMS defined at the signal level.
    cFile.write("\n")
    for frame in candb.frames:
        for sig in frame:
            for a in sig.values.keys():
                cFile.write ("#define CAN_ENUM_" + sig.name.upper() + "_" + sig.values[a].upper().replace(" ", "") + " " + str(a) + "\n")
    # Add macros for ENUMS defined at the global level.
    cFile.write("\n")
    for vt in candb.valueTables:
        for a in candb.valueTables[vt].keys():
            cFile.write ("#define CAN_ENUM_" + vt.upper() + "_" + candb.valueTables[vt][a].upper().replace(" ", "") + " " + str(a) + "\n")
    cFile.write('''
typedef struct CANPacket {
   uint32_t id; // Actual physical ID of the packet
   uint8_t data[8]; // Data
   uint8_t bufferNum; // Only applicable for Rx, which buffer it landed in
   uint8_t length; // Only applies to sending packets. We don't know how long incoming packets are.
} CANPacket;

void canWrapInit();

// Global function pointer to point to the function
// when a packet is received through CAN
void (*CANPacketReceived)(CANPacket *);

void canSendPacket(CANPacket *packet);

void setCANPacketRxCallback(void (*ReceiveCallbackArg)(CANPacket *packet));
''')
    for frame in candb.frames:
        cFile.write("typedef struct " + frame.name + " {\n")
        for sig in frame:
            cFile.write("    "
                + getSignalSize(sig, frame, floatList)
                + " " + sig.name
                + "; // "
                + (sig.unit if sig.unit != "" else " (No Units)")
                + "\n"
            )
        cFile.write("} " + frame.name + ";\n\n")
    for frame in candb.frames:
        cFile.write("void encode"
            + frame.name + "(" + frame.name + " *input, CANPacket* output);\n")
        cFile.write("void decode" + frame.name + "(CANPacket *input, "
            + frame.name + " *output);\n\n")
    cFile.write('''#endif /* DSBASE_INTERFACES_CANWRAP_H_ */\n''')
    cFile.close()
def cMainDecodeInteger(frame, sig, sigType):
    return ("    output -> "
        + sig.name
        + " = ("
        + sigType
        + ") (((fullData & ((uint64_t) "
        + str(hex(int(str(int((-1 + 10 ** sig.signalsize)//9)), 2)))
        + (" << " + str(int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize)) if int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize) != 0.0 else "")
        + (")) >> " + str(int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize)) if int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize) != 0.0 else "))")
        + (") * " + (str(int(sig.factor)) if int(sig.factor) - float(sig.factor) == 0.0 else str(sig.factor)) if sig.factor != 1.0 else ")")
        + (" + " + (str(int(sig.offset)) if int(sig.offset) - float(sig.offset) == 0.0 else str(sig.offset)) if sig.offset != 0.0 else "")
        + ");\n")
def cMainDecodeFloat(frame, sig, sigType):
    # output -> NormalFloat = (*((float *)(&((uint32_t) ((fullData & ((uint64_t) 0xffffffff << 8)) >> 8))))) * factor + offset;
    if sigType == "float":
        out = "    uint32_t temp" + sig.name
        out += " = (uint32_t) ((fullData & ((uint64_t) "
        out += str(hex(int(str(int((-1 + 10 ** sig.signalsize)//9)), 2)))
        out += (" << " + str(int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize)) if int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize) != 0.0 else "")
        out +=(")) >> " + str(int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize)) if int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize) != 0.0 else "))")
        out += (");\n")
        out += "    output -> "
        out += sig.name
        out += " = (*((float *)(&(" + "temp" + sig.name
        out += ("))))")
        out += (" * " + str(sig.factor) if sig.factor != 1.0 else "")
        out += ("+" + str(sig.offset) if sig.offset != 0.0 else "")
        out += ";\n"
        return out;
    else:
        out = "    uint64_t temp" + sig.name
        out += " = (uint64_t) ((fullData & ((uint64_t) "
        out += str(hex(int(str(int((-1 + 10 ** sig.signalsize)//9)), 2)))
        out += (" << " + str(int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize)) if int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize) != 0.0 else "")
        out +=(")) >> " + str(int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize)) if int(frame.size * 8 - int(sig.getStartbit()) - sig.signalsize) != 0.0 else "))")
        out += (");\n")
        out += "output -> "
        out += sig.name
        out += " = (*((double *)(&(" + "temp" + sig.name
        out += ("))))")
        out += (" * " + str(sig.factor) if sig.factor != 1.0 else "")
        out += ("+" + str(sig.offset) if sig.offset != 0.0 else "")
        out += ";\n"
        return out;
def cMainEncodeInteger(frame, sig, sigType):
    return ("    fullPacketData |= (((uint64_t)((input -> "
        + sig.name
        + (" - " + (str(int(sig.offset)) if int(sig.offset) - float(sig.offset) == 0.0 else str(sig.offset)) if sig.offset != 0.0 else "")
        + ((") / " + (str(int(sig.factor)) if int(sig.factor) - float(sig.factor) == 0.0 else str(sig.factor))) if (sig.factor != 1.0) else (")"))
        + (")) & " + str(hex(int(str(int((-1 + 10 ** sig.signalsize)//9)), 2))))
        + (") << " + str(64 - int(sig.getStartbit()) - sig.signalsize) if 64 - int(sig.getStartbit()) - sig.signalsize != 0 else ")")
        + ";\n")
def cMainEncodeFloat(frame, sig, sigType):
    # fullPacketData |= ((uint64_t)(*((uint32_t *)(&(((input -> SigName) - offset) / factor))))) << slidybit;
    if sigType == "float":
        return (
            "    const float temp"
            + sig.name
            + " = ((input -> "
            + sig.name
            + (" - " + str(sig.offset) + ")" if sig.offset != 0.0 else ")")
            + (") / " + str(sig.factor) if (sig.factor != 1.0) else (")"))
            + ";\n"
            + "    fullPacketData |= ((uint64_t)(*((uint32_t *)(&(temp"
            + sig.name
            + ")))))"
            + (" << " + str(64 - int(sig.getStartbit()) - sig.signalsize) if 64 - int(sig.getStartbit()) - sig.signalsize != 0 else "")
            + ";\n")
    else:
        return (
            "    const double temp"
            + sig.name
            + " = ((input -> "
            + sig.name
            + (" - " + str(sig.offset) + ")" if sig.offset != 0.0 else ")")
            + (") / " + str(sig.factor) if (sig.factor != 1.0) else (")"))
            + ";\n"
            + "    fullPacketData |= ((uint64_t)(*((uint64_t *)(&(temp"
            + sig.name
            + ")))))"
            + (" << " + str(64 - int(sig.getStartbit()) - sig.signalsize) if 64 - int(sig.getStartbit()) - sig.signalsize != 0 else "")
            + ";\n")
def createCMain(candb, cFileName, floatList):
    cFile = open(cFileName, "w")
    cFile.write('''/*
 * canwrap.c
 *
 *  Created on: Aug 14, 2017
 *      Author: emoryeng
 */

#include "canwrap.h"
#include "../core/can.h"

//void canPacketInit(uint8_t boardNum){
//    canInit();
//    setTheFilter(CAN_MASK_0, 0x01 << boardNum);
//    setTheFilter(CAN_FILTER_0, 0x01 << boardNum);
//    setTheFilter(CAN_FILTER_1, 0x01 << boardNum);
//    setTheFilter(CAN_MASK_1, 0x01 << boardNum);
//    setTheFilter(CAN_FILTER_2, 0x01 << boardNum);
//    setTheFilter(CAN_FILTER_3, 0x01 << boardNum);
//    setTheFilter(CAN_FILTER_4, 0x01 << boardNum);
//    setTheFilter(CAN_FILTER_5, 0x01 << boardNum);
//}
void setMaskOrFilter(uint8_t addr, uint32_t filter){
    setTheFilter(addr, filter);
}

void wrapCB0(uint8_t length, uint8_t* data, uint32_t id){
    CANPacket packet = {0};
    CANPacket *p = &packet;
    p -> id = id;
    uint8_t i;
    for(i = 0 ; i < length; i++){
        p -> data[i] = data[i];
    }
    p -> bufferNum = 0;
    CANPacketReceived(p);
}

void wrapCB1(uint8_t length, uint8_t* data, uint32_t id){
    CANPacket packet = {0};
    CANPacket *p = &packet;
    p -> id = id;
    uint8_t i;
    for(i = 0 ; i < length; i++){
        p -> data[i] = data[i];
    }
    p -> bufferNum = 1;
    CANPacketReceived(p);
}

void canWrapInit(){
    canInit();
    setReceiveCallback0(wrapCB0);
    setReceiveCallback1(wrapCB1);
}

void reverseArray(uint8_t arr[], uint8_t start, uint8_t end)
{
    uint8_t temp;
    if (start >= end)
        return;
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseArray(arr, start+1, end-1);
}

void canSendPacket(CANPacket *packet){
    uint8_t tech[5] = {
       (uint8_t) (packet->id >> 21),
       (uint8_t) (packet->id >> 16) & 0x03 | (uint8_t) (packet->id >> 13) & 0xE0 | 0x08,
       (uint8_t) (packet->id >> 8),
       (uint8_t) packet->id,
       packet->length
    };
    canSend(0,tech, packet->data);
}

void setCANPacketRxCallback(void (*ReceiveCallbackArg)(CANPacket *packet)) {
    CANPacketReceived = ReceiveCallbackArg;
}

// AUTOGEN STUFF HERE

''')
    for frame in candb.frames:
        # Decode Function Implementation
        cFile.write("void decode"
            + frame.name + "(CANPacket *input, " + frame.name + " *output){\n")
        cFile.write("    uint64_t *thePointer = (uint64_t *) input -> data;\n")
        cFile.write("    reverseArray(input -> data, 0, 7);\n")
        cFile.write("    const uint64_t fullData = *thePointer;\n")
        for sig in frame:
            sigType = getSignalSize(sig, frame, floatList)
            if sigType == "float" or sigType == "double":
                cFile.write(cMainDecodeFloat(frame, sig, sigType))
            else:
                cFile.write(cMainDecodeInteger(frame, sig, sigType))
        cFile.write("}\n\n")
        # Encode Function Implementation
        cFile.write("void encode" + frame.name
            + "(" + frame.name + " *input, CANPacket *output){\n")
        # cFile.write("    CANPacket *output = malloc(sizeof(CANPacket));\n")
        cFile.write("    output -> id = "
            + (str(frame.id) if frame.id != 2147483648 else "0")
            + ";\n")
        cFile.write("    output -> length = " + str(frame.size) + ";\n")
        cFile.write("    uint64_t fullPacketData = 0x0000000000000000;\n")
        for sig in frame:
            sigType = getSignalSize(sig, frame, floatList)
            if sigType == "float" or sigType == "double":
                cFile.write(cMainEncodeFloat(frame, sig, sigType))
            else:
                cFile.write(cMainEncodeInteger(frame, sig, sigType))
        cFile.write("    uint64_t *thePointer = (uint64_t *) (&(output -> data));\n")
        cFile.write("    *thePointer = fullPacketData;\n")
        cFile.write("    reverseArray((output->data), 0, 7);\n")
        cFile.write("}\n\n")
    cFile.close()

def handleFloats(infile):
    file = open(infile, "r")
    out = []
    for line in file.readlines():
        linearr = line.split()
        if len(linearr) > 4 and linearr[0] == "SIG_VALTYPE_":
            out.append(((int(linearr[1]) - 2 ** (32 - 1) if int(linearr[1]) != 2147483648 else 2147483648), linearr[2], int(linearr[4][0])))
    return out
def main():
    # Command line stuff
    from optparse import OptionParser
    usage = """\n  %prog import-file\n    import-file: *.dbc|*.dbf|*.kcd|*.arxml|*.json|*.xls(x)|*.sym"""
    parser = OptionParser(usage=usage)
    (cmdlineOptions, args) = parser.parse_args()
    if len(args) < 1:
        parser.print_help()
        sys.exit(1)
    infile = args[0]
    # Make the CAN Object from DBC
    CANObj = toPyObject(infile, "", **cmdlineOptions.__dict__)
    # Now, CANMatrix has an issue where it doesn't correctly id floats.
    # For now, we have to work around this manually

    # Make the directory and generate the output files.
    if not os.path.exists("codeGenOutput"):
        os.makedirs("codeGenOutput")
    floatList = handleFloats(infile)
    createCHeader(CANObj, "codeGenOutput/canwrap.h", floatList)
    createCMain(CANObj, "codeGenOutput/canwrap.c", floatList)

if __name__ == '__main__':
    sys.exit(main())
