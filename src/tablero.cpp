#include "tablero.h"

tablero::tablero() {//constructor para poder guardar las posiciones
    for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8; col++) {
            float x = col * tamañocuadrado;
            float y = fila * tamañocuadrado;
            casillas[fila][col] = Casillas(fila, col, x, y);
        }
    }
};

void tablero::dibujar_tablero() {
    // Dibuja el tablero 8x8
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Calcula las coordenadas de la esquina superior izquierda de la casilla
            float x = i * tamañocuadrado;
            float y = j * tamañocuadrado;

            // Si la fila par columna par o fila impar columna impar es negro de lo contrario blanco
            if ((i % 2 != 0 && j%2!=0)||(i%2==0&&j%2==0)) {
                glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
            }
            else{
            
                glColor3f(0.0f, 0.0f, 0.0f);
            }

            // va dibujando los cuadrados a medida que avanzan los bucles
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + tamañocuadrado, y);
            glVertex2f(x + tamañocuadrado, y + tamañocuadrado);
            glVertex2f(x, y + tamañocuadrado);
            glEnd();
        }
    }
}