#include <stdint.h>
#include <stdbool.h>

uint8_t g_ram[256] = {0};

bool vram_escribir(uint8_t fila, uint8_t col, char c) {
    if (fila >= 4 || col >= 4) return false;
    
    uint8_t dir = 0xF0 + (fila * 4) + col; /* Dirección VRAM */
    g_ram[dir] = (uint8_t)c;
    return true;
}

void vram_scroll_arriba(void) {
    for (int f = 0; f < 3; f++) {
        for (int c = 0; c < 4; c++) {
            g_ram[0xF0 + (f * 4) + c] = g_ram[0xF0 + ((f + 1) * 4) + c];
        }
    }
    for (int c = 0; c < 4; c++) {
        g_ram[0xF0 + (3 * 4) + c] = 0x20; /* 0x20 es Espacio en blanco en ASCII */
    }
}

int main() {
    // Función main para permitir compilación
    return 0;
}
