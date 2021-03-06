#include <msp430.h> 

#include "SUBSYSTEMNAME_MODULENAME.h"
#include "bsp/bsp.h"
#include "core/can.h"
#include "interfaces/canwrap.h"

#define BOARD_NUM (0x05)

#define LED_BLUE (0x01)
#define LED_RED (0x04)
#define LED_YELLOW (0x02)

/*
 * main.c
 */
// Send back the same reply

void newCB(CANPacket *packet){

    Message4OddSizes pst = {0};
    CANPacket ppst = {0};
    CANPacket *pps = &ppst;
    pst.OddSize3 = 69;
    encodeMessage4OddSizes(&pst,pps);
    canSendPacket(pps);
}

int main(void) {

    // ALWAYS START main() with bspInit(<systemname>) as the FIRST line of code
    bspInit(Module_Test);

    canWrapInit();
    setCANPacketRxCallback(newCB);

    P3DIR |= 0x20;
    P3OUT |= 0x20;




#if defined(__DEBUG__)

    // TODO:  Insert debug-specific stuff here, including registering info/status/action handlers, etc.

#endif  //  __DEBUG__
	
	return 0;
}
