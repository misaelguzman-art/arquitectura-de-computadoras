#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t cursor_vram;
    uint8_t ram[256];
} PCState;

PCState g_pc = { .cursor_vram = 0xF0 };

/* Stubs (simulaciones) para funciones externas necesarias en compilacion */
bool cola_teclado_desencolar(uint8_t *salida_ascii) {
    *salida_ascii = 'A';
    return true; 
}

void monitor_actualizar_pantalla(void) {
    // Stub vacío para permitir enlace del compilador
}

bool terminal_procesar_siguiente_tecla(void) {
    uint8_t tecla;
    if (!cola_teclado_desencolar(&tecla)) return false;

    if (tecla == 0x08 || tecla == 0x7F) { /* BACKSPACE */
        if (g_pc.cursor_vram > 0xF0) {
            g_pc.cursor_vram--;
            g_pc.ram[g_pc.cursor_vram] = 0x20; /* Borra carácter */
        }
    } else if (tecla >= 32 && tecla <= 126) { /* Imprimibles */
        if (g_pc.cursor_vram <= 0xFF) {
            g_pc.ram[g_pc.cursor_vram] = tecla;
            g_pc.cursor_vram++;
        }
    }
    monitor_actualizar_pantalla();
    return true;
}

int main() {
    // Función main para permitir compilación
    return 0;
}
