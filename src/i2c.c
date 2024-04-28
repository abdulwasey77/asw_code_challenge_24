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

   uint8_t fullScaleConfig;
   if(i2c_read(I2C_BUS_ADDR1,CTRL_REG2_ADDR,1,&fullScaleConfig) != STATUS_OK)
   {
        printf("Failed to read the data\n");
        return STATUS_ERROR;
   }
    // Shift right by 5 bits and mask with 0x03
    // assume the values is 10111011 so shift 5 bit is 00000101
    // when it is & with 100 will left with FS[1:0]
    fullScaleConfig = (fullScaleConfig >> 5) & 0x03; 

    switch (fullScaleConfig) {
        case FULL_SCALE_4GAUSS:
            printf("Full-scale range: ±4 gauss\n");
            break;
        case FULL_SCALE_8GAUSS:
            printf("Full-scale range: ±8 gauss\n");
            break;
        case FULL_SCALE_12GAUSS:
            printf("Full-scale range: ±12 gauss\n");
            break;
        case FULL_SCALE_16GAUSS:
            printf("Full-scale range: ±16 gauss\n");
            break;
        default:
            printf("Invalid full-scale range\n");
            break;
    }

   return STATUS_OK;

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

uint8_t outputDataRate;
   if(i2c_read(I2C_BUS_ADDR1,CTRL_REG1_ADDR,1,&outputDataRate) != STATUS_OK)
   {
        printf("Failed to read the data\n");
        return STATUS_ERROR;
   }
    // Shift right by 2 bits and mask with 0xE0
    // assume the values is 10111011 so shift 2 bit is 00101110
    // when it is & with 00111000 (0x38) will left with DO[2:0]
    outputDataRate = (outputDataRate >> 2) & 0x38; 

    switch (outputDataRate) {
        case DATA_RATE_625mHz:
            printf("Output Data Rate Configuration: 0.625Hz\n");
            break;
        case DATA_RATE_1250mHz:
            printf("Output Data Rate Configuration: 1.25Hz\n");
            break;
        case DATA_RATE_2500mHz:
            printf("Output Data Rate Configuration: 2.50Hz\n");
            break;
        case DATA_RATE_5Hz:
            printf("Output Data Rate Configuration: 5Hz\n");
            break;
        case DATA_RATE_10Hz:
            printf("Output Data Rate Configuration: 10Hz\n");
            break;
        case DATA_RATE_20Hz:
            printf("Output Data Rate Configuration: 20Hz\n");
            break;
        case DATA_RATE_40Hz:
            printf("Output Data Rate Configuration: 40Hz\n");
            break;
        default:
            printf("Invalid Data Rate Configuration\n");
            break;
    }

   
   return STATUS_OK;

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
status_t set_outputDataRate_config(uint8_t output_dataRate_Set){

   uint8_t outputDataRate;
   if(i2c_read(I2C_BUS_ADDR1,CTRL_REG1_ADDR,1,&outputDataRate) != STATUS_OK)
   {
        printf("Failed to read the data\n");
        return STATUS_ERROR;
   }
    if(output_dataRate_Set<=0x07){
        // Take a mask 0x007 (00000111) Shift right by 2 (00011100) and flip it (11100011)
        // Now & it with the original will get rid of DO[0:2] from the register
        outputDataRate &= ~(0x07 << 2); 

        // give two bit shift to the output_dataRate_Set and combine it with final data
        outputDataRate |= (output_dataRate_Set << 2);
        if(i2c_write(I2C_BUS_ADDR1,CTRL_REG1_ADDR,1,&outputDataRate) != STATUS_OK)
        {
            printf("Failed to write the data\n");
            return STATUS_ERROR;
        }else{
            printf("Successfully write the data\n"); 
        }

    }else{
        printf("Invalid Value of output Data Rate\n");
        return STATUS_ERROR;
    }


   return STATUS_OK;

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

    uint8_t intConfig;
    // Read the current value of the interrupt configuration register
    if(i2c_read(I2C_BUS_ADDR1, INT_CFG_ADDR, 1, &intConfig) != STATUS_OK) {
        printf("Failed to read the interrupt config\n");
        return STATUS_ERROR;
    }

    if(value) {
        // If value is true, set the INE bit (bit 0) to 1
        intConfig |= 0x01; // Set bit 0
    } else {
        // If enable is false, clear the INE bit (bit 0) to 0
        intConfig &= ~0x01; // Clear bit 0
    }

    // Write the modified value back to the interrupt configuration register
    if(i2c_write(I2C_BUS_ADDR1, INT_CFG_ADDR, 1, &intConfig) != STATUS_OK) {
        printf("Failed to write the interrupt config\n");
        return STATUS_ERROR;
    }

    return STATUS_OK;
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
status_t read_outputData_axis(axis_t axis){
   uint8_t low_byte, high_byte;
   uint16_t axis_data;

   switch (axis)
   {
   case xaxis:
    if(i2c_read(I2C_BUS_ADDR1, OUT_X_L_ADDR, 1, &low_byte) != STATUS_OK) {
        printf("Failed to read the interrupt config\n");
        return STATUS_ERROR;
    }
    if(i2c_read(I2C_BUS_ADDR1, OUT_X_H_ADDR, 1, &high_byte) != STATUS_OK) {
        printf("Failed to read the interrupt config\n");
        return STATUS_ERROR;
    }
    break;

    case yaxis:
    if (i2c_read(I2C_BUS_ADDR1, OUT_Y_L_ADDR, 1, &low_byte) != STATUS_OK) {
        printf("Failed to read the low byte of y-axis\n");
        return STATUS_ERROR;
    }
    if (i2c_read(I2C_BUS_ADDR1, OUT_Y_H_ADDR, 1, &high_byte) != STATUS_OK) {
        printf("Failed to read the high byte of y-axis\n");
        return STATUS_ERROR;
    }
    break;

    case zaxis:
    if (i2c_read(I2C_BUS_ADDR1, OUT_Z_L_ADDR, 1, &low_byte) != STATUS_OK) {
        printf("Failed to read the low byte of z-axis\n");
        return STATUS_ERROR;
    }
    if (i2c_read(I2C_BUS_ADDR1, OUT_Z_H_ADDR, 1, &high_byte) != STATUS_OK) {
        printf("Failed to read the high byte of z-axis\n");
        return STATUS_ERROR;
    }
    break;
   
   default:
        printf("Invalid axis\n");
        return STATUS_ERROR;
    break;
   }

    // Combine the low and high bytes
    axis_data = (uint16_t)high_byte << 8 | low_byte;

    printf("Data for axis  %d: %d\n", axis, axis_data);

}