#include "mundo.h"
#include <iostream>
mundo::mundo() {
    inicializa();
}

void mundo::inicializa() {
    alfil.setPosicion(0, 0, 0.0, 5.0);
    reyNegro.setPosicion(0, 0, 7.0, 3.0);

    for (int i = 0; i < 8; i++) {  
        peonesNegros[i].setPosicion(0, 0, 6.0, i);
    }

}

void mundo::dibuja() {
    table.dibujar_tablero();
    caballo.dibujar_caballo();
    alfil.dibujar_alfil();
    reyNegro.dibujar_rey();

    for (int i = 0; i < 8; i++) {
        peonesNegros[i].dibujar_peon();
    }
}


void mundo::clickRaton(int fila, int columna) {

    Casillas destino = table.getCasilla(fila, columna);
    std::cout << "raton en: (" << fila << ", " << columna << ")" << std::endl;
    caballo.setPosicion(fila, columna, destino.getX(), destino.getY());

}


