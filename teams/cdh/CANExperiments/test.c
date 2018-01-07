void decodePPTMisfireCount(CANPacket *input, PPTMisfireCount *output){
    uint64_t *thePointer = (uint64_t *) input -> data;
    reverseArray(input -> data, 0, 7);
    const uint64_t fullData = *thePointer;
    output -> totalMisfires2 = (uint32_t) (((fullData & ((uint64_t) 0b1111111111111111 << 0)) >> 0) * 1 + 0);
    output -> totalMisfires1 = (uint32_t) (((fullData & ((uint64_t) 0b1111111111111111 << 16)) >> 16) * 1 + 0);
}

void encodePPTMisfireCount(PPTMisfireCount *input, CANPacket *output){
    output -> id = 6;
    uint64_t fullPacketData = 0x0000000000000000;
    fullPacketData |= ((uint64_t)((input -> totalMisfires2 - 0) / 1)) << 32;
    fullPacketData |= ((uint64_t)((input -> totalMisfires1 - 0) / 1)) << 48;
    uint64_t *thePointer = (uint64_t *) (&(output -> data));
    *thePointer = fullPacketData;
    reverseArray((output->data), 0, 7);
}

void decodePPTTimingStatus(CANPacket *input, PPTTimingStatus *output){
    uint64_t *thePointer = (uint64_t *) input -> data;
    reverseArray(input -> data, 0, 7);
    const uint64_t fullData = *thePointer;
    output -> averageChargeTime = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 32)) >> 32) * 2 + 0);
    output -> minutesSinceSuccessfulFire = (uint32_t) (((fullData & ((uint64_t) 0b1111111111111111 << 0)) >> 0) * 1 + 0);
    output -> minutesSinceAttemptedFire = (uint32_t) (((fullData & ((uint64_t) 0b1111111111111111 << 16)) >> 16) * 1 + 0);
    output -> medianChargeTime = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 40)) >> 40) * 2 + 0);
}

void encodePPTTimingStatus(PPTTimingStatus *input, CANPacket *output){
    output -> id = 5;
    uint64_t fullPacketData = 0x0000000000000000;
    fullPacketData |= ((uint64_t)((input -> averageChargeTime - 0) / 2)) << 48;
    fullPacketData |= ((uint64_t)((input -> minutesSinceSuccessfulFire - 0) / 1)) << 16;
    fullPacketData |= ((uint64_t)((input -> minutesSinceAttemptedFire - 0) / 1)) << 32;
    fullPacketData |= ((uint64_t)((input -> medianChargeTime - 0) / 2)) << 56;
    uint64_t *thePointer = (uint64_t *) (&(output -> data));
    *thePointer = fullPacketData;
    reverseArray((output->data), 0, 7);
}

void decodeFiringStatus(CANPacket *input, FiringStatus *output){
    uint64_t *thePointer = (uint64_t *) input -> data;
    reverseArray(input -> data, 0, 7);
    const uint64_t fullData = *thePointer;
    output -> successfullFires1 = (uint32_t) (((fullData & ((uint64_t) 0b1111111111111111 << 0)) >> 0) * 1 + 0);
    output -> successfulFires2 = (uint32_t) (((fullData & ((uint64_t) 0b1111111111111111 << 16)) >> 16) * 1 + 0);
    output -> numberOfMisfires = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 32)) >> 32) * 1 + 0);
    output -> lastFiringRate = (uint8_t) (((fullData & ((uint64_t) 0b11111111 << 40)) >> 40) * 1 + 0);
}

void encodeFiringStatus(FiringStatus *input, CANPacket *output){
    output -> id = 4;
    uint64_t fullPacketData = 0x0000000000000000;
    fullPacketData |= ((uint64_t)((input -> successfullFires1 - 0) / 1)) << 16;
    fullPacketData |= ((uint64_t)((input -> successfulFires2 - 0) / 1)) << 32;
    fullPacketData |= ((uint64_t)((input -> numberOfMisfires - 0) / 1)) << 48;
    fullPacketData |= ((uint64_t)((input -> lastFiringRate - 0) / 1)) << 56;
    uint64_t *thePointer = (uint64_t *) (&(output -> data));
    *thePointer = fullPacketData;
    reverseArray((output->data), 0, 7);
}

void decodeVoltageCurrentInfo(CANPacket *input, VoltageCurrentInfo *output){
    uint64_t *thePointer = (uint64_t *) input -> data;
    reverseArray(input -> data, 0, 7);
    const uint64_t fullData = *thePointer;
    output -> adcCurrent = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 0)) >> 0) * 25 + 0);
    output -> com1Current = (uint8_t) (((fullData & ((uint64_t) 0b11111111 << 8)) >> 8) * 1 + 0);
    output -> com2Current = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 16)) >> 16) * 25 + 0);
    output -> LineVoltage = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 24)) >> 24) * 25 + 0);
    output -> rahsCurrent = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 32)) >> 32) * 25 + 0);
}

void encodeVoltageCurrentInfo(VoltageCurrentInfo *input, CANPacket *output){
    output -> id = 3;
    uint64_t fullPacketData = 0x0000000000000000;
    fullPacketData |= ((uint64_t)((input -> adcCurrent - 0) / 25)) << 24;
    fullPacketData |= ((uint64_t)((input -> com1Current - 0) / 1)) << 32;
    fullPacketData |= ((uint64_t)((input -> com2Current - 0) / 25)) << 40;
    fullPacketData |= ((uint64_t)((input -> LineVoltage - 0) / 25)) << 48;
    fullPacketData |= ((uint64_t)((input -> rahsCurrent - 0) / 25)) << 56;
    uint64_t *thePointer = (uint64_t *) (&(output -> data));
    *thePointer = fullPacketData;
    reverseArray((output->data), 0, 7);
}

void decodeBatteryStatus(CANPacket *input, BatteryStatus *output){
    uint64_t *thePointer = (uint64_t *) input -> data;
    reverseArray(input -> data, 0, 7);
    const uint64_t fullData = *thePointer;
    output -> batteryFullChargeCount = (uint32_t) (((fullData & ((uint64_t) 0b1111111111111111 << 0)) >> 0) * 1 + 0);
    output -> batteryTemperature = (int16_t) (((fullData & ((uint64_t) 0b11111111 << 24)) >> 24) * 1.5 + 0);
    output -> batteryVoltage = (uint32_t) (((fullData & ((uint64_t) 0b11111111 << 32)) >> 32) * 25 + 0);
    output -> LowestBatteryVoltage = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 40)) >> 40) * 25 + 0);
    output -> underVoltageEvents = (uint32_t) (((fullData & ((uint64_t) 0b1111111111111111 << 48)) >> 48) * 1 + 0);
}

void encodeBatteryStatus(BatteryStatus *input, CANPacket *output){
    output -> id = 2;
    uint64_t fullPacketData = 0x0000000000000000;
    fullPacketData |= ((uint64_t)((input -> batteryFullChargeCount - 0) / 1)) << 0;
    fullPacketData |= ((uint64_t)((input -> batteryTemperature - 0) / 1.5)) << 24;
    fullPacketData |= ((uint64_t)((input -> batteryVoltage - 0) / 25)) << 32;
    fullPacketData |= ((uint64_t)((input -> LowestBatteryVoltage - 0) / 25)) << 40;
    fullPacketData |= ((uint64_t)((input -> underVoltageEvents - 0) / 1)) << 48;
    uint64_t *thePointer = (uint64_t *) (&(output -> data));
    *thePointer = fullPacketData;
    reverseArray((output->data), 0, 7);
}

void decodePowerStatus(CANPacket *input, PowerStatus *output){
    uint64_t *thePointer = (uint64_t *) input -> data;
    reverseArray(input -> data, 0, 7);
    const uint64_t fullData = *thePointer;
    output -> powerGeneration = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 0)) >> 0) * 150 + 0);
    output -> overcurrent = (uint8_t) (((fullData & ((uint64_t) 0b11111111 << 8)) >> 8) * 1 + 0);
    output -> outputPower = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 16)) >> 16) * 150 + 0);
    output -> outputConfig = (uint8_t) (((fullData & ((uint64_t) 0b11111111 << 24)) >> 24) * 1 + 0);
    output -> coulombCount = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 40)) >> 40) * 15 + 0);
    output -> batteryFullyCharged = (uint8_t) (((fullData & ((uint64_t) 0b11111111 << 48)) >> 48) * 1 + 0);
    output -> avePowerGeneration = (uint16_t) (((fullData & ((uint64_t) 0b11111111 << 56)) >> 56) * 100 + 0);
}

void encodePowerStatus(PowerStatus *input, CANPacket *output){
    output -> id = 1;
    uint64_t fullPacketData = 0x0000000000000000;
    fullPacketData |= ((uint64_t)((input -> powerGeneration - 0) / 150)) << 0;
    fullPacketData |= ((uint64_t)((input -> overcurrent - 0) / 1)) << 8;
    fullPacketData |= ((uint64_t)((input -> outputPower - 0) / 150)) << 16;
    fullPacketData |= ((uint64_t)((input -> outputConfig - 0) / 1)) << 24;
    fullPacketData |= ((uint64_t)((input -> coulombCount - 0) / 15)) << 40;
    fullPacketData |= ((uint64_t)((input -> batteryFullyCharged - 0) / 1)) << 48;
    fullPacketData |= ((uint64_t)((input -> avePowerGeneration - 0) / 100)) << 56;
    uint64_t *thePointer = (uint64_t *) (&(output -> data));
    *thePointer = fullPacketData;
    reverseArray((output->data), 0, 7);
}

void decodeMCUStatus(CANPacket *input, MCUStatus *output){
    uint64_t *thePointer = (uint64_t *) input -> data;
    reverseArray(input -> data, 0, 7);
    const uint64_t fullData = *thePointer;
    output -> numOfTurnons = (uint32_t) (((fullData & ((uint64_t) 0b1111111111111111 << 0)) >> 0) * 1 + 0);
    output -> minutesSinceTurnon = (uint32_t) (((fullData & ((uint64_t) 0b1111111111111111 << 16)) >> 16) * 1 + 0);
    output -> MCUTemp = (int8_t) (((fullData & ((uint64_t) 0b11111111 << 40)) >> 40) * 1 + 0);
}

void encodeMCUStatus(MCUStatus *input, CANPacket *output){
    output -> id = 0;
    uint64_t fullPacketData = 0x0000000000000000;
    fullPacketData |= ((uint64_t)((input -> numOfTurnons - 0) / 1)) << 16;
    fullPacketData |= ((uint64_t)((input -> minutesSinceTurnon - 0) / 1)) << 32;
    fullPacketData |= ((uint64_t)((input -> MCUTemp - 0) / 1)) << 56;
    uint64_t *thePointer = (uint64_t *) (&(output -> data));
    *thePointer = fullPacketData;
    reverseArray((output->data), 0, 7);
}
