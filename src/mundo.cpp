#include "mundo.h"
#include <iostream>
mundo::mundo() {
    inicializa();
}

void mundo::inicializa() {
    alfil.setPosicion(0, 0, 0.0, 5.0);

   // reyNegro = Rey("bin/imagenes/rey_negro.png");
    reyNegro.setPosicion(0, 0, 7.0, 3.0);

    //reyBlanco = Rey("bin/imagenes/rey_blanco.png");
    reyBlanco.setPosicion(0, 0, 0.0, 4.0);

    for (int i = 0; i < 8; i++) {
        //peonesNegros[i] = Peon("bin/imagenes/peon_negro.png");
        peonesNegros[i].setPosicion(0, 0, 6.0, i);

        //peonesBlancos[i] = Peon("bin/imagenes/peon_blanco.png");
        peonesBlancos[i].setPosicion(0, 0, 1.0, i);
    }

}

void mundo::dibuja() {
    table.dibujar_tablero();
    caballo.dibujar_caballo();
    alfil.dibujar_alfil();
    reyBlanco.dibujar_rey();
    reyNegro.dibujar_rey();

    for (int i = 0; i < 8; i++) {
        peonesNegros[i].dibujar_peon();
        peonesBlancos[i].dibujar_peon();
    }
}


void mundo::clickRaton(int fila, int columna) {

    Casillas destino = table.getCasilla(fila, columna);
    std::cout << "raton en: (" << fila << ", " << columna << ")" << std::endl;
    caballo.setPosicion(fila, columna, destino.getX(), destino.getY());

}


