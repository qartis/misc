#include <stdio.h>
#include <stdlib.h>
#include <modbus/modbus.h>
#include <errno.h>
#include <string.h>

#define NB_REGISTERS 20
#define SERIAL_DEVICE "/dev/ttyUSB1"
#define BAUD_RATE 9600
#define SLAVE_ID 5

int main(void) {
    modbus_t *ctx;
    modbus_mapping_t *mb_mapping;
    uint8_t query[MODBUS_RTU_MAX_ADU_LENGTH];
    uint16_t registers[NB_REGISTERS] = {0};
    int rc;

    ctx = modbus_new_rtu(SERIAL_DEVICE, BAUD_RATE, 'N', 8, 1);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to create the libmodbus context\n");
        return -1;
    }

    modbus_set_slave(ctx, SLAVE_ID);

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return -1;
    }

    mb_mapping = modbus_mapping_new(0, 0, NB_REGISTERS, 0);
    if (mb_mapping == NULL) {
        fprintf(stderr, "Failed to allocate the mapping: %s\n", modbus_strerror(errno));
        modbus_close(ctx);
        modbus_free(ctx);
        return -1;
    }

    // Initialize the mapping with our register values
    for (int i = 0; i < NB_REGISTERS; i++) {
        mb_mapping->tab_registers[i] = registers[i];
    }

    printf("Listening for Modbus RTU requests on %s...\n", SERIAL_DEVICE);

    for (;;) {
        rc = modbus_receive(ctx, query);
        if (rc > 0) {
            modbus_reply(ctx, query, rc, mb_mapping);

	    mb_mapping->tab_registers[9]++;
            // Update our local copy of registers
            for (int i = 0; i < NB_REGISTERS; i++) {
                registers[i] = mb_mapping->tab_registers[i];
            }

            printf("Registers: ");
            for (int i = 0; i < NB_REGISTERS; i++) {
                printf("%d ", registers[i]);
            }
            printf("\n");
        } else if (rc == -1) {
            // Error in communication
            fprintf(stderr, "Error in communication: %s\n", modbus_strerror(errno));
            continue;
        }
    }

    printf("Quit the loop: %s\n", modbus_strerror(errno));

    modbus_mapping_free(mb_mapping);
    modbus_close(ctx);
    modbus_free(ctx);

    return 0;
}
