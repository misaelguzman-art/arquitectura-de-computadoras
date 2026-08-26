#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool sumar_uint8_con_carry(uint8_t a, uint8_t b, uint8_t *resultado) {
    unsigned char carry_flag;

    asm volatile(
        "add %2, %0\n\t"
        "setc %1\n\t"
        : "+q"(a), "=q"(carry_flag)
        : "q"(b)
        : "cc"
    );

    *resultado = a;
    return carry_flag != 0;
}

int main(void) {
    uint8_t res;

    bool hay_carry = sumar_uint8_con_carry(200, 50, &res);
    printf("200 + 50 = %u | Carry Flag: %s\n", res, hay_carry ? "SI (Acarreo)" : "NO");

    hay_carry = sumar_uint8_con_carry(200, 60, &res);
    printf("200 + 60 = %u | Carry Flag: %s\n", res, hay_carry ? "SI (Acarreo)" : "NO");

    return 0;
}
