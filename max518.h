/*!
 * @brief   Arduino/Teensy Library for MAX517/MAX518/MAX519 8Bit DACs
 *
 * @file    max518.h
 *
 * @remark
 *
 * @ingroup arduino_max518
 *
 * @author  Yash Bansod
 */
/*------------------------------------------        Include Files           ------------------------------------------*/
#include <stdint.h>
#include <Wire.h>

/*------------------------------------------            Definitions         ------------------------------------------*/
#ifndef ARDUINO_MAX518_H
#define ARDUINO_MAX518_H

class Max518{
public:
/*!
 * Default I2C address of the DAC. Assuming both AD0 and AD1 are pulled to ground.
 * See Page 9, Figure 6 in https://datasheets.maximintegrated.com/en/ds/MAX517-MAX519.pdf
 */
    static const uint8_t DEF_ADDR           = 0x2C;     // Binary - 0010 1100

/*!
 * Some Commands for the DAC.
 * See Page 9, Figure 7 in https://datasheets.maximintegrated.com/en/ds/MAX517-MAX519.pdf
 */
    static const uint8_t RESET_CMD          = 0x10;
    static const uint8_t POWER_UP_CMD       = 0x00;
    static const uint8_t POWER_DOWN_CMD     = 0x08;
    static const uint8_t SET_OUTPUT_1_CMD   = 0x00;
    static const uint8_t SET_OUTPUT_2_CMD   = 0x01;

    Max518(uint8_t dev_addr = DEFAULT_ADDRESS);

    bool reset() const;
    bool power_up() const;
    bool power_down() const;
    bool set_output_1(uint8_t out_1) const;
    bool set_output_2(uint8_t out_2) const;
    bool set_output_1_2(uint8_t out_1, uint8_t out_2) const;

private:
    uint8_t dev_addr_;

};

Max518::Max518(uint8_t dev_addr) {
    dev_addr_ = dev_addr;
    Wire.begin();
}

bool Max518::reset() const {
    Wire.beginTransmission(dev_addr_);
    Wire.write(RESET_CMD);
    return (Wire.endTransmission() == 0);
}

bool Max518::power_up() const {
    Wire.beginTransmission(dev_addr_);
    Wire.write(POWER_UP_CMD);
    return (Wire.endTransmission() == 0);
}

bool Max518::power_down() const {
    Wire.beginTransmission(dev_addr_);
    Wire.write(POWER_DOWN_CMD);
    return (Wire.endTransmission() == 0);
}

bool Max518::set_output_1(uint8_t out_1) const {
    Wire.beginTransmission(dev_addr_);
    Wire.write(SET_OUTPUT_1_CMD);
    Wire.write(out_1);
    return (Wire.endTransmission() == 0);
}

bool Max518::set_output_1(uint8_t out_2) const {
    Wire.beginTransmission(dev_addr_);
    Wire.write(SET_OUTPUT_2_CMD);
    Wire.write(out_2);
    return (Wire.endTransmission() == 0);
}

bool Max518::set_output_1_2(uint8_t out_1, uint8_t out_2) const {
    Wire.beginTransmission(dev_addr_);
    Wire.write(SET_OUTPUT_1_CMD);
    Wire.write(out_1);
    Wire.write(SET_OUTPUT_2_CMD);
    Wire.write(out_2);
    return (Wire.endTransmission() == 0);
}

#endif //ARDUINO_MAX518_H
