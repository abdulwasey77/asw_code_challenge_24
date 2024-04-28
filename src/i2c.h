#ifndef I2C_HEADER_H
#define I2C_HEADER_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

// Bus Address
#define I2C_BUS_ADDR1 0x1E
#define I2C_BUS_ADDR2 0x1C

// Control registers Address
#define CTRL_REG1_ADDR 0x20
#define CTRL_REG2_ADDR 0x21

// Interrupt register Address
#define INT_CFG_ADDR 0x30

// Data Output registers Address
#define OUT_X_L_ADDR 0x28
#define OUT_X_H_ADDR 0x29
#define OUT_Y_L_ADDR 0x2A
#define OUT_Y_H_ADDR 0x2B
#define OUT_Z_L_ADDR 0x2C
#define OUT_Z_H_ADDR 0x2D


typedef enum {
    STATUS_OK,
    STATUS_ERROR
} status_t;

typedef enum {
    xaxis,
    yaxis,
    zaxis
} axis_t;

status_t i2c_read(
    uint8_t bus_address,
    uint8_t register_address,
    uint16_t length,
    uint8_t *buffer);

status_t i2c_write(
    uint8_t bus_address,
    uint8_t register_address,
    uint16_t length,
    uint8_t *buffer);

status_t interrupt_setting(
    bool value);

status_t get_fullScale_config();

status_t get_outputDataRate_config();

status_t set_outputDataRate_config(uint8_t output_dataRate);

status_t interrupt_setting(bool value);

status_t read_outputData_axis(axis_t);

#endif
