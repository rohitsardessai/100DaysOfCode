#include <stdint.h>
#include <stdio.h>

int is_big_endian(void)
{
    typedef union {
        uint32_t i;
        char c[4];
    } end_t;

    end_t e;
    e.i = (uint32_t)1;

    return e.c[3];
}

// print any datatype
void printBits(size_t const size, void const *const ptr)
{
    unsigned char *b = (unsigned char *)ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    printf("\n");
}

int main(void)
{
    printf("System is %s-endian.\n", is_big_endian() ? "big" : "little");

    uint8_t u_num = 0b00011010;
    printBits(sizeof(uint8_t), &u_num);

    u_num |= (1 << 2); // set 3rd bit
    printBits(sizeof(uint8_t), &u_num);
    printf("Value of 3rd bit is %i\n", ((u_num >> 2) & 1));

    u_num &= ~(1 << 2); // reset 3rd bit
    printBits(sizeof(uint8_t), &u_num);
    printf("Value of 3rd bit is %i\n", ((u_num >> 2) & 1));

    return 0;
}