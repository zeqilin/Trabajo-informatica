#include "Rey.h"
#include <cmath>

//Constructor del rey
Rey::Rey(int x, int y, bool color) : pieza(x, y, color) {}

//Implementación del método mover para el rey
bool Rey::mover(int nuevaX, int nuevaY, pieza* tablero[8][8]) {
    // El rey puede moverse una casilla en cualquier dirección
    if (abs(nuevaX - x) <= 1 && abs(nuevaY - y) <= 1) {
        // Aplicar gravedad si la casilla está ocupada
        while (tablero[nuevaX][nuevaY] != nullptr && nuevaX < 7) {
            nuevaX++;
        }

        // Mover la pieza
        tablero[x][y] = nullptr;  // Eliminar pieza anterior
        tablero[nuevaX][nuevaY] = this;  // Colocar la pieza en la nueva posición
        x = nuevaX;
        y = nuevaY;
        return true;
    }
    return false;  // Movimiento inválido
}