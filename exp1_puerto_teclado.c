#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t address_bus;
    uint8_t data_bus;
    bool io_read;
    bool mem_read;
} SystemBuses;

typedef struct {
    uint8_t reg_status;
    uint8_t reg_data;
} TecladoHardware;

SystemBuses g_bus;
TecladoHardware gi_teclado;

// Declaración anticipada
void tick_controlador_teclado(SystemBuses *bus, TecladoHardware *kb);

uint8_t cpu_instruccion_in(uint8_t puerto) {
    g_bus.address_bus = puerto;
    g_bus.io_read = true;
    g_bus.mem_read = false;
    
    tick_controlador_teclado(&g_bus, &gi_teclado);
    
    uint8_t dato = g_bus.data_bus;
    g_bus.io_read = false;
    return dato;
}

void tick_controlador_teclado(SystemBuses *bus, TecladoHardware *kb) {
    if (bus->io_read) {
        if (bus->address_bus == 0x01) {
            bus->data_bus = kb->reg_status;
        } else if (bus->address_bus == 0x02) {
            bus->data_bus = kb->reg_data;
            kb->reg_status = 0; /* Handshake automático */
        }
    }
}

int main() {
    // Función main para permitir compilación
    return 0;
}
