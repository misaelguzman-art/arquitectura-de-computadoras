#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool sumar_int8_con_overflow(int8_t a, int8_t b, int8_t *resultado) {
    unsigned char overflow_flag;

    asm volatile(
        "add %2, %0\n\t"
        "seto %1\n\t"
        : "+q"(a), "=q"(overflow_flag)
        : "q"(b)
        : "cc"
    );

    *resultado = a;
    return overflow_flag != 0;
}

int main(void) {
    int8_t res;

    bool hay_overflow = sumar_int8_con_overflow(100, 20, &res);
    printf("100 + 20 = %d | Overflow Flag: %s\n", res, hay_overflow ? "SI" : "NO");

    hay_overflow = sumar_int8_con_overflow(100, 30, &res);
    printf("100 + 30 = %d | Overflow Flag: %s\n", res, hay_overflow ? "SI (Error de signo)" : "NO");

    return 0;
}
