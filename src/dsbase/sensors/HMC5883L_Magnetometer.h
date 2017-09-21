/*
 * HMC5883L_Magnetometer.h
 *
 *  Created on: Mar 31, 2017
 *      Author: jeffc
 */

#ifndef _HMC5883L_MAGNETOMETER_H
#define _HMC5883L_MAGNETOMETER_H

// Core definitions for chip
#define MAG_HMC5883L_I2C_7BIT_ADDRESS     0x1E    // Fixed in hardware for this chip (!) - BECOMES 0x3C for writes, 0x3D for reads

// Register addresses (NOTE:  listed in decimal in datasheet)
#define MAG_HMC5883L_REG_ADDR_CRA     0       // Config register A
#define MAG_HMC5883L_REG_ADDR_CRB     1       // Config register B
#define MAG_HMC5883L_REG_ADDR_MR      2       // Mode register
#define MAG_HMC5883L_REG_ADDR_DXRA    3       // Data output registers
#define MAG_HMC5883L_REG_ADDR_DXRB    4       //      xxxA = MSB, xxxB = LSB
#define MAG_HMC5883L_REG_ADDR_DZRA    5       // NOTE:  XZY ordering intentional!
#define MAG_HMC5883L_REG_ADDR_DZRB    6
#define MAG_HMC5883L_REG_ADDR_DYRA    7
#define MAG_HMC5883L_REG_ADDR_DYRB    8
#define MAG_HMC5883L_REG_ADDR_SR      9       // Status register
#define MAG_HMC5883L_REG_ADDR_IDRA    10      // Identification registers
#define MAG_HMC5883L_REG_ADDR_IDRB    11
#define MAG_HMC5883L_REG_ADDR_IDRC    12

// Useful shorthand register names
#define MAG_HMC5883L_CRA         MAG_HMC5883L_REG_ADDR_CRA
#define MAG_HMC5883L_CRB         MAG_HMC5883L_REG_ADDR_CRB
#define MAG_HMC5883L_MR          MAG_HMC5883L_REG_ADDR_MR
#define MAG_HMC5883L_SR          MAG_HMC5883L_REG_ADDR_SR

// Various shortcuts
#define MAG_HMC5883L_ALL_DATA_OUTPUTS            0x06   // Used with data output read command
#define MAG_HMC5883L_XYZ_OUTPUT_REG_ADDR_START   MAG_HMC5883L_REG_ADDR_DXRA  // Reset to this after fetching data

// Config flags - Configuration Register A
#define MAG_HMC5883L_MEASURE_MODE_NORMAL         0x00
#define MAG_HMC5883L_MEASURE_MODE_POS_BIAS       0x01
#define MAG_HMC5883L_MEASURE_MODE_NEG_BIAS       0x02
#define MAG_HMC5883L_MEASURE_MODE_DEFAULT        MAG_HMC5883L_MEASURE_MODE_NORMAL

#define MAG_HMC5883L_CONTINUOUS_OUTPUT_RATE_P75  0x00    // Approximate output rates IF IN CONTINUOUS OPERATING MODE
#define MAG_HMC5883L_CONTINUOUS_OUTPUT_RATE_1P5  0x04    // Measured in Hz, P='.'
#define MAG_HMC5883L_CONTINUOUS_OUTPUT_RATE_3    0x08    // Faster rates possible through RDY/DRDY monitoring
#define MAG_HMC5883L_CONTINUOUS_OUTPUT_RATE_7P5  0x0C
#define MAG_HMC5883L_CONTINUOUS_OUTPUT_RATE_15   0x10
#define MAG_HMC5883L_CONTINUOUS_OUTPUT_RATE_30   0x14
#define MAG_HMC5883L_CONTINUOUS_OUTPUT_RATE_75   0x18
#define MAG_HMC5883L_CONTINUOUS_OUTPUT_RATE_DEFAULT  MAG_HMC5883L_CONTINUOUS_OUTPUT_RATE_15

#define MAG_HMC5883L_AVERAGE_1_SAMPLE            0x00
#define MAG_HMC5883L_AVERAGE_2_SAMPLE            0x20
#define MAG_HMC5883L_AVERAGE_4_SAMPLE            0x40
#define MAG_HMC5883L_AVERAGE_8_SAMPLE            0x60
#define MAG_HMC5883L_AVERAGE_SAMPLE_DEFAULT      MAG_HMC5883L_AVERAGE_1_SAMPLE

#define MAG_HMC5883L_CONFIG_REGISTER_A_DEFAULT_MASK (0 | MAG_HMC5883L_MEASURE_MODE_DEFAULT | MAG_HMC5883L_CONTINUOUS_OUTPUT_RATE_DEFAULT | MAG_HMC5883L_AVERAGE_SAMPLE_DEFAULT)

// Config flags - Configuration Register B
#define MAG_HMC5883L_GAIN_1370       0x00
#define MAG_HMC5883L_GAIN_1090       0x20
#define MAG_HMC5883L_GAIN_820        0x40
#define MAG_HMC5883L_GAIN_660        0x60
#define MAG_HMC5883L_GAIN_440        0x80
#define MAG_HMC5883L_GAIN_390        0xA0
#define MAG_HMC5883L_GAIN_330        0xC0
#define MAG_HMC5883L_GAIN_230        0xE0
#define MAG_HMC5883L_GAIN_DEFAULT    MAG_HMC5883L_GAIN_1090
#define MAG_HMC5883L_CONFIG_REGISTER_B_DEFAULT_MASK (0 | MAG_HMC5883L_GAIN_DEFAULT)

// Mag Gain nT Conversion Factors
#define MAG_HMC5883L_GAIN_1370_NT_CONVERSION_FACTOR       73.0
#define MAG_HMC5883L_GAIN_1090_NT_CONVERSION_FACTOR       92.0
#define MAG_HMC5883L_GAIN_820_NT_CONVERSION_FACTOR        122.0
#define MAG_HMC5883L_GAIN_660_NT_CONVERSION_FACTOR        152.0
#define MAG_HMC5883L_GAIN_440_NT_CONVERSION_FACTOR        227.0
#define MAG_HMC5883L_GAIN_390_NT_CONVERSION_FACTOR        256.0
#define MAG_HMC5883L_GAIN_330_NT_CONVERSION_FACTOR        303.0
#define MAG_HMC5883L_GAIN_230_NT_CONVERSION_FACTOR        435.0

#define MAG_HMC5883L_GAIN_MAX                       MAG_HMC5883L_GAIN_1370
#define MAG_HMC5883L_GAIN_MAX_CONVERSION_FACTOR     MAG_HMC5883L_GAIN_1370_NT_CONVERSION_FACTOR

// Config flags - Mode Register
#define MAG_HMC5883L_OPERATING_MODE_CONTINUOUS   0x00
#define MAG_HMC5883L_OPERATING_MODE_SINGLE       0x01
#define MAG_HMC5883L_OPERATING_MODE_IDLE         0x02  // NOTE:  0x03 also indicates idle
#define MAG_HMC5883L_OPERATING_MODE_DEFAULT      MAG_HMC5883L_OPERATING_MODE_SINGLE

#define MAG_HMC5883L_I2C_SPEED_STANDARD          0x00
#define MAG_HMC5883L_I2C_SPEED_HIGHSPEED         0x80
#define MAG_HMC5883L_I2C_SPEED_DEFAULT           MAG_HMC5883L_I2C_SPEED_STANDARD

#define MAG_HMC5883L_MODE_REGISTER_DEFAULT_MASK (0 | MAG_HMC5883L_OPERATING_MODE_DEFAULT | MAG_HMC5883L_I2C_SPEED_DEFAULT)

// Status Register
#define MAG_HMC5883L_STATUS_OUTPUT_READY         0x01    // All 6 data outputs populated with new data
#define MAG_HMC5883L_STATUS_OUTPUT_LOCKED        0x02    // Data outputs not yet fully updated


// Conversion factors
// TODO:  Consider making this a lookup table based on current gain setting, to avoid falling out of sync
#define HMC5883L_CONVERSION_FACTOR_RAW_TO_NANOTESLAS  MAG_HMC5883L_GAIN_MAX_CONVERSION_FACTOR
#define HMC5883L_CONVERSION_FACTOR_RAW_TO_TESLAS  (HMC5883L_CONVERSION_FACTOR_RAW_TO_NANOTESLAS / 1000000000.0)




#endif /* _HMC5883L_MAGNETOMETER_H */
