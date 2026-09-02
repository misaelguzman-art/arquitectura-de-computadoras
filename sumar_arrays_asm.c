#include <stdio.h>

void sumar_arrays_asm(int a[], int b[], int resultado[], int n) {
    for (int i = 0; i < n; i++) {
        asm volatile(
            "movl (%[a], %[indice], 4), %%eax\n\t"
            "addl (%[b], %[indice], 4), %%eax\n\t"
            "movl %%eax, (%[resultado], %[indice], 4)"
            :
            : [a] "r"(a),
              [b] "r"(b),
              [resultado] "r"(resultado),
              [indice] "r"((long)i)
            : "eax", "cc", "memory"
        );
    }
}

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {10, 20, 30, 40, 50};
    int resultado[5];

    sumar_arrays_asm(a, b, resultado, 5);

    printf("Resultado con ensamblador: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
