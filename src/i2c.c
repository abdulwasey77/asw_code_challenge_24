#include "i2c.h"

/*
************* i2c read **************
pass the parameter to read 12c data from the register
input parameters
    uint8_t bus_address         //12c address if SD0/SA1 high 0011110b otherwise 0011100b
    uint8_t register_address    //reg address (05h-33h)
    uint16_t length             //reg length
    uint8_t *buffer             //reg data

Output
    Status_t

*/

status_t i2c_read(
    uint8_t bus_address,
    uint8_t register_address,
    uint16_t length,
    uint8_t *buffer)
{
    printf(
        "read [%d] bytes from bus [%d] for register [%d]\n",
        length,
        bus_address,
        register_address);

    /* Setting the output to some arbitrary value */
    for (size_t i = 0; i < length; ++i) {
        buffer[i] = 0xff;
    }

    return STATUS_OK;
}

/*
************* i2c write **************
pass the parameter to write 12c data from the register
input parameters
    uint8_t bus_address         //12c address if SD0/SA1 high 0011110b otherwise 0011100b
    uint8_t register_address    //reg address (05h-33h)
    uint16_t length             //reg length
    uint8_t *buffer             //reg data

Output
    Status_t

*/

status_t i2c_write(
    uint8_t bus_address,
    uint8_t register_address,
    uint16_t length,
    uint8_t *buffer)
{
    printf(
        "write [%d] bytes to bus [%d] for register [%d]\n\t",
        length,
        bus_address,
        register_address);

    for (size_t i = 0; i < length; ++i) {
        printf("%p", buffer);
    }
    printf("\n");
    return STATUS_OK;
}

/*
************* Get full-scale configuration **************
This function is used to the get the full scale configuration of the LIS3MDLTR-3

input parameters
    None

Output
    Status_t

useful information
The CTR_REG2 (21h) will be used to read the full-scale configration 
FS0 (bit 5) and FS1 (bit 6) will give the desired output
FS[1:0] = 00; //+-4 gauss
FS[1:0] = 01; //+-8 gauss
FS[1:0] = 10; //+-12 gauss
FS[1:0] = 11; //+-16 gauss

*/
status_t get_fullScale_config(){

   // i2c_read(bus_address,register_address,length,&buffer);

   // i2c_write(bus_address,register_address,length,&buffer);

}

/*
************* get the output data rate  **************
This function is used to the get the output data rate of the LIS3MDLTR-3

input parameters
    None

Output
    Status_t

useful information
The CTR_REG1 (20h) will be used to read the output data rate configration 
DO1 (bit 2), DO1 (bit 3) and DO1 (bit 4) will give the desired output
DO[2:0] = 000; //0.625Hz
DO[2:0] = 001; //1.25Hz
DO[2:0] = 010; //2.55Hz
DO[2:0] = 011; //5Hz
DO[2:0] = 100; //10Hz
DO[2:0] = 101; //20Hz
DO[2:0] = 110; //40Hz
DO[2:0] = 111; //80Hz

*/
status_t get_outputDataRate_config(){

   // i2c_read(bus_address,register_address,length,&buffer);

   // i2c_write(bus_address,register_address,length,&buffer);

}

/*
************* set the output data rate  **************
This function is used to the get the output data rate of the LIS3MDLTR-3

input parameters
    uint8_t output_dataRate //three bit value 0b000-0b111

Output
    Status_t

useful information
The CTR_REG1 (20h) will be used to read the output data rate configration 
DO1 (bit 2), DO1 (bit 3) and DO1 (bit 4) will give the desired output
DO[2:0] = 000; //0.625Hz
DO[2:0] = 001; //1.25Hz
DO[2:0] = 010; //2.55Hz
DO[2:0] = 011; //5Hz
DO[2:0] = 100; //10Hz
DO[2:0] = 101; //20Hz
DO[2:0] = 110; //40Hz
DO[2:0] = 111; //80Hz

*/
status_t set_outputDataRate_config(uint8_t output_dataRate){

   // i2c_read(bus_address,register_address,length,&buffer);

   // i2c_write(bus_address,register_address,length,&buffer);

}


/*
************* interrupt settting **************
pass boolean value to the function to enable disable the interrupt
input parameters
    boolean value

Output
    Status

useful information
interrupt reg INT_CFG (30h)
INE (bit 0) will be used to enable and disable the interrupt
INE = 0; //disabled
INE = 1; //enable
*/
status_t interrupt_setting(bool value){

   // i2c_read(bus_address,register_address,length,&buffer);

   // i2c_write(bus_address,register_address,length,&buffer);

}


/*
************* Read the output data of specified axis **************
pass boolean value to the function to enable disable the interrupt
input parameters
    axis_t //xaxis,yaxis,zaxis

Output
    Status_t

useful information
x-axis => reg OUT_X_L (28h), OUT_X_H (29h)
y-axis => OUT_Y_L (2Ah), OUT_Y_H (2Bh)
z-axis => OUT_Z_L (2Ch), OUT_Z_H (2Dh)
*/
status_t read_outputData_axis(axis_t){

   // i2c_read(bus_address,register_address,length,&buffer);

   // i2c_write(bus_address,register_address,length,&buffer);

}