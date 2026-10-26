#!/bin/bash
echo "=== COMPILANDO CONTROLADORES ANSI C ==="
echo "1. Compilando Experimento 1 (Puertos)..."
gcc -std=c99 -Wall -Wextra -pedantic exp1_puerto_teclado.c -o exp1

echo "2. Compilando Experimento 2 (Cola FIFO)..."
gcc -std=c99 -Wall -Wextra -pedantic exp2_cola_teclado.c -o exp2

echo "3. Compilando Experimento 3 (VRAM)..."
gcc -std=c99 -Wall -Wextra -pedantic exp3_vram_monitor.c -o exp3

echo "4. Compilando Reto Integrador (Terminal)..."
gcc -std=c99 -Wall -Wextra -pedantic reto_integrador_terminal.c -o terminal

echo "¡Todos los archivos han sido compilados con éxito bajo estándar C99!"
