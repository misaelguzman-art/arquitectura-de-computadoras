#include <stdbool.h>
#include <stdio.h>

bool restar_y_detectar_zero(int a, int b, int *resultado) {
    unsigned char zero_flag;

    asm volatile(
        "sub %2, %0\n\t"
        "setz %1\n\t"
        : "+r"(a), "=q"(zero_flag)
        : "r"(b)
        : "cc"
    );

    *resultado = a;
    return zero_flag != 0;
}

int main(void) {
    int res;

    bool es_cero = restar_y_detectar_zero(42, 42, &res);
    printf("42 - 42 = %d | Zero Flag activa: %s\n", res, es_cero ? "SI" : "NO");

    es_cero = restar_y_detectar_zero(50, 20, &res);
    printf("50 - 20 = %d | Zero Flag activa: %s\n", res, es_cero ? "SI" : "NO");

    return 0;
}
