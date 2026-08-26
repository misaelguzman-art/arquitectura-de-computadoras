#include <stdio.h>

#define TAMANO 5

int main(void) {
    int arreglo[TAMANO] = {0};

    for (int i = 0; i < TAMANO; i++) {
        arreglo[i] = (i + 1) * 10;
    }

    printf("Contenido del arreglo:\n");
    for (int i = 0; i < TAMANO; i++) {
        printf("arreglo[%d] = %d\n", i, arreglo[i]);
    }

    return 0;
}
