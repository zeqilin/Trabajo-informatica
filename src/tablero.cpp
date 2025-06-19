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
    for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8; col++) {
            float x = col * tamañocuadrado;
            float y = fila * tamañocuadrado;

            // Si la fila par columna par o fila impar columna impar es negro de lo contrario blanco
            if ((fila % 2 != 0 && col%2!=0)||(fila%2==0&&col%2==0)) {
                glColor3f(0.36f, 0.25f, 0.20f);//color marron para visualizar las piezas negras
            }
            else{
            
                glColor3f(0.93f, 0.86f, 0.75f);//color beige para visualizar las piezas blancas
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