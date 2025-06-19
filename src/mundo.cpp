#include "mundo.h"
#include <iostream>
mundo::mundo() {
    inicializa();
}

void mundo::inicializa() {
    Casillas c1 = table.getCasilla(6, 0); // b8
    Casillas c2 = table.getCasilla(1, 0); // g8
   // std::cout << "Caballo arriba pos: (" << c1.getX() << ", " << c1.getY() << ")\n";
    //std::cout << "Caballo abajo pos: (" << c2.getX() << ", " << c2.getY() << ")\n";

    // Asignar posiciones
   
    alfil.setPosicion(0, 0, 0.0, 5.0);
    reyNegro.setPosicion(0, 0, 7.0, 3.0);
    for (int i = 0; i < 8; i++) {
        peonesNegros[i].setPosicion(0, 0, 6.0, i);
    }
    caballoNegroarriba.setPosicion(6, 0, c1.getX(), c1.getY());
    caballoNegroabajo.setPosicion(1, 0, c2.getX(), c2.getY());
    std::cout << "Caballo1 en: (" << caballoNegroarriba.getPosicion().getFila() << "," << caballoNegroarriba.getPosicion().getColumna() << ")\n";
    std::cout << "Caballo2 en: (" << caballoNegroabajo.getPosicion().getFila() << "," << caballoNegroabajo.getPosicion().getColumna() << ")\n";


}

void mundo::dibuja() {
    table.dibujar_tablero();
    
   /**alfil.dibujar_alfil();
    reyNegro.dibujar_rey();
    

    for (int i = 0; i < 8; i++) {
        peonesNegros[i].dibujar_peon();
    */
    caballoNegroarriba.dibujar();
    caballoNegroabajo.dibujar();
}


void mundo::clickRaton(int fila, int columna) {

    Casillas destino = table.getCasilla(fila, columna);
    caballoNegroabajo.setPosicion(fila, columna, destino.getX(), destino.getY());
    std::cout << "raton en: (" << fila << ", " << columna << ")" << std::endl;
    std::cout << "raton en: (" << destino.getX() << ", " << destino.getY() << ")" << std::endl;
}


