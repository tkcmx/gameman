#include <stdio.h>
#include <stdint.h>

int disassmble_instruction(uint8_t *code, uint16_t pc) {
    uint8_t *instruction = &code[pc];
    int opbytes = 1;

    printf("%04x\t", pc);
    switch (*instruction) {
        case 0x00: // NOP
            printf("NOP");
            opbytes = 3;
            break;
        
        case 0x01: // LD BC, u16
            printf("LD\tBC\t0x%02x%02x", code[2], code[1]);
            opbytes = 3;
            break;

        case 0x02: // LD (BC), A
            printf("LD\t(BC)\tA");
            opbytes = 1;
            break;

        case 0x03: // INC BC
            printf("INC\tBC");
            opbytes = 1;
            break;

        case 0x04: // INC B
            printf("INC\tB");
            opbytes = 1;
            break;

        case 0x05: // DEC B
            printf("DEC\tB");
            opbytes = 1;
            break;

        case 0x06: // LD B, u8
            printf("LD\tB\t0x%02x", code[1]);
            opbytes = 2;
            break;

        case 0x07: // RLCA
            printf("RLCA");
            opbytes = 1;
            break;
    }

    printf("\n");
}