# AAC-Clydespace Avionics Software Challenge
You are given the LIS3MDLTR 3-Axis Magnetometer sensor. The data sheet is
located at `doc/lism3mdl.pdf`

## Task Description
You must use the C API defined in `i2c.h` to operate on an I2C bus.

We provide example stub implementations of this API in `i2c.c`. You are free to
extend the provided stub functions for the API.

Please write a device driver that implements the following API:
- Get the full-scale configuration
- Get and set the output data rate
- Enable or disable the interrupt pin
- Read the output data of a specified axis

## Development Requiremnts
You are provided this minimal repository, `aac-code-challenge`, please perform
your work on branch `<candidate_name>`

Documentation can be found in `aac-code-challenge/doc`

Once complete, please repackage and email back this repo to your interviewers

## Scope
You shouldn't need to spend more than a couple of hours on the task.

This is not a closed book assessment.

## Development Progress
* Full-scale Configuration: Developed `get_fullScale_config()` to read and interpret the full-scale range configuration from the `CTRL_REG2 (0x21)`. The function extracts the FS[1:0] configuration to determine the sensor's measurement range.
* Output Data Rate: Functions `get_outputDataRate_config()` and `set_outputDataRate_config()` manage the data rate settings via `CTRL_REG1 (0x20)`. These functions allow reading the current rate and adjusting it between 0.625Hz and 80Hz based on operational needs.
* Interrupt Management: Implemented `interrupt_setting()` to control the interrupt generation feature through the `INT_CFG (0x30)` register, using a boolean input to enable or disable interrupts.
* Axis Data Read:  Created functions for each axis `read_outputData_axis()` to fetch magnetic field data from the sensor. Specific registers for each axis are:
    - X-axis: `OUT_X_L_ADDR` (0x28) and `OUT_X_H_ADDR` (0x29)
    - Y-axis: `OUT_Y_L_ADDR` (0x2A) and `OUT_Y_H_ADDR` (0x2B)
    - Z-axis: `OUT_Z_L_ADDR` (0x2C) and `OUT_Z_H_ADDR` (0x2D)

## Extra Thoughts
If you have time, answer the following questions:
- What changes you would make to this interfaces for use in an RTOS
environment?
    * Task Scheduling and Preemption: Modify the I2C read/write operations to be compatible with RTOS task scheduling. This involves managing I2C operations through tasks or threads that can be scheduled according to priority, ensuring timely responses in a multi-threaded environment.
    * Mutexes for Resource Management: Use mutexes or semaphores to manage access to the I2C bus. This is essential to avoid bus contention and ensure that only one task can access the bus at a time, preventing data corruption and ensuring data integrity.
    
- How might the I2C API be improved
     * Error Handling Enhancements: Expand the error handling to provide more detailed error codes rather than just STATUS_OK and STATUS_ERROR. This could include specific errors for bus faults, data corruption, or timeout conditions.
    * Timeout Implementation: Implement timeout mechanisms for I2C operations to recover from bus lock-up or prolonged waiting times. This would be crucial for improving the reliability of I2C communications, especially in a hardware fault scenario.

