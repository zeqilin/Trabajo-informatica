#include "mundo.h"
#include <iostream>
mundo::mundo() {
    inicializa();
}

void mundo::inicializa() {
    Casillas c1 = table.getCasilla(6, 0); // b8
    Casillas c2 = table.getCasilla(1, 0); //g8
    Casillas c3 = table.getCasilla(3, 0);
    Casillas c5 = table.getCasilla(3, 7);
   // std::cout << "Caballo arriba pos: (" << c1.getX() << ", " << c1.getY() << ")\n";
    //std::cout << "Caballo abajo pos: (" << c2.getX() << ", " << c2.getY() << ")\n";

    // Asignar posiciones
   
    alfil.setPosicion(0, 0, 0.0, 5.0);
    reyNegro = Rey(3, 0, Color::Negro);
    reyNegro.setPosicion(3, 0, c3.getX(), c3.getY());
    reyBlanco = Rey(3, 7, Color::Blanco);
    reyBlanco.setPosicion(3, 7, c5.getX(), c5.getY());
    for (int i = 0; i < 8; i++) {
        Casillas c4 = table.getCasilla(i, 1); // fila 6 para peones negros
        peonesNegros[i].setPosicion(i, 1, c4.getX(), c4.getY());
    }
    
    caballoNegroarriba= Caballo(6, 0, Color::Negro);
    caballoNegroabajo = Caballo(1, 0, Color::Negro);
    caballoNegroarriba.setPosicion(6, 0, c1.getX(), c1.getY());
    caballoNegroabajo.setPosicion(1, 0, c2.getX(), c2.getY());
    std::cout << "Caballo1 en: (" << caballoNegroarriba.getPosicion().getFila() << "," << caballoNegroarriba.getPosicion().getColumna() << ")\n";
    std::cout << "Caballo2 en: (" << caballoNegroabajo.getPosicion().getFila() << "," << caballoNegroabajo.getPosicion().getColumna() << ")\n";


}

void mundo::dibuja() {
    table.dibujar_tablero();
    
   //alfil.dibujar_alfil();
       
    caballoNegroarriba.dibujar();
    caballoNegroabajo.dibujar();
    reyNegro.dibujar();
    reyBlanco.dibujar();
    for (int i = 0; i < 8; i++) {
        peonesNegros[i].dibujar();
    }

}


void mundo::clickRaton(int fila, int columna) {

    Casillas destino = table.getCasilla(fila, columna);
    caballoNegroarriba.setPosicion(fila, columna, destino.getX(), destino.getY());
    std::cout << "raton en: (" << fila << ", " << columna << ")" << std::endl;
    std::cout << "raton en: (" << destino.getX() << ", " << destino.getY() << ")" << std::endl;
}


