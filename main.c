#include "src/i2c.c"

int main() {
    status_t status;

    // Get the full-scale configuration
    printf("Getting full-scale configuration...\n");
    status = get_fullScale_config();
    if (status != STATUS_OK) {
        printf("Error getting full-scale configuration.\n");
    }

    // Set output data rate to 10Hz
    printf("Setting output data rate to 10Hz...\n");
    status = set_outputDataRate_config(DATA_RATE_10Hz);
    if (status != STATUS_OK) {
        printf("Error setting output data rate.\n");
    }

    // Get output data rate configuration
    printf("Getting output data rate configuration...\n");
    status = get_outputDataRate_config();
    if (status != STATUS_OK) {
        printf("Error getting output data rate configuration.\n");
    }

    // Enable interrupt
    printf("Enabling interrupt...\n");
    status = interrupt_setting(true);
    if (status != STATUS_OK) {
        printf("Error enabling interrupt.\n");
    }

    // Read data from the X-axis
    printf("Reading data from X-axis...\n");
    status = read_outputData_axis(xaxis);
    if (status != STATUS_OK) {
        printf("Error reading data from X-axis.\n");
    }

    return 0;
}
