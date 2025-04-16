#include "Alfil.h"
#include <cmath>

//Constructor del alfil
Alfil::Alfil(int x, int y, bool color) : pieza(x, y, color) {}

//Implementación del método mover para el alfil
bool Alfil::mover(int nuevaX, int nuevaY, pieza* tablero[8][8]) {
    // Verificar que el movimiento es diagonal
    if (abs(nuevaX - x) == abs(nuevaY - y)) {
        int dx = (nuevaX > x) ? 1 : -1;
        int dy = (nuevaY > y) ? 1 : -1;

        int tempX = x + dx;
        int tempY = y + dy;

        // Revisa que no haya piezas en el camino (excepto para comer)
        while (tempX != nuevaX && tempY != nuevaY) {
            if (tablero[tempX][tempY] != nullptr) {
                break;  // Detener el movimiento si hay una pieza
            }
            tempX += dx;
            tempY += dy;
        }

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