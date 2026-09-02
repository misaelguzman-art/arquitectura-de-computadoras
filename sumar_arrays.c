#include <stdio.h>

void sumar_arrays(int a[], int b[], int resultado[], int n) {
    for (int i = 0; i < n; i++) {
        resultado[i] = a[i] + b[i];
    }
}

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {10, 20, 30, 40, 50};
    int resultado[5];

    sumar_arrays(a, b, resultado, 5);

    printf("Resultado: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
