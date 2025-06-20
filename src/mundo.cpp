#include "mundo.h"
#include <iostream>
mundo::mundo() {
    inicializa();
}

void mundo::inicializa() {
    Peon::cargarSprites();
    Casillas c1 = table.getCasilla(6, 0); // b8
    Casillas c2 = table.getCasilla(1, 0); //g8
    Casillas c3 = table.getCasilla(3, 0);
    Casillas c4 = table.getCasilla(3, 7);
   // std::cout << "Caballo arriba pos: (" << c1.getX() << ", " << c1.getY() << ")\n";
    //std::cout << "Caballo abajo pos: (" << c2.getX() << ", " << c2.getY() << ")\n";

    // Asignar posiciones
   
    alfil.setPosicion(0, 0, 0.0, 5.0);
    reyNegro = new Rey(3, 0, Color::Negro);
    reyNegro->setPosicion(3, 0, c3.getX(), c3.getY());
    piezas.push_back(reyNegro);

    reyBlanco = new Rey(3, 7, Color::Blanco);
    reyBlanco->setPosicion(3, 7, c4.getX(), c4.getY());
    piezas.push_back(reyBlanco);

    for (int i = 0; i < 8; i++) {
        Casillas c = table.getCasilla(i, 1);
        peonesNegros[i] = new Peon(i, 1, Color::Negro);
        peonesNegros[i]->setPosicion(i, 1, c.getX(), c.getY());
        piezas.push_back(peonesNegros[i]);
    }
    for (int i = 0; i < 8; i++) {
        Casillas c = table.getCasilla(i, 6);
        peonesBlancos[i] = new Peon(i, 6, Color::Blanco);
        peonesBlancos[i]->setPosicion(i, 6, c.getX(), c.getY());
        piezas.push_back(peonesBlancos[i]);
    }
    
    caballoNegroarriba = new Caballo(6, 0, Color::Negro);
    caballoNegroarriba->setPosicion(6, 0, c1.getX(), c1.getY());
    piezas.push_back(caballoNegroarriba);

    caballoNegroabajo = new Caballo(1, 0, Color::Negro);
    caballoNegroabajo->setPosicion(1, 0, c2.getX(), c2.getY());
    piezas.push_back(caballoNegroabajo);

    std::cout << "Caballo1 en: (" << caballoNegroarriba->getPosicion().getFila() << "," << caballoNegroarriba->getPosicion().getColumna() << ")\n";
    std::cout << "Caballo2 en: (" << caballoNegroabajo->getPosicion().getFila() << "," << caballoNegroabajo->getPosicion().getColumna() << ")\n";


}

void mundo::dibuja() {
    table.dibujar_tablero();
    
   //alfil.dibujar_alfil();
       
    /*caballoNegroarriba.dibujar();
    caballoNegroabajo.dibujar();
    reyNegro->dibujar();
    reyBlanco->dibujar();
    for (int i = 0; i < 8; i++) {
        peonesNegros[i]->dibujar();
    }
    for (int i = 0; i < 8; i++) {
        peonesBlancos[i]->dibujar();
    }*/
    for (auto pieza : piezas) {
        pieza->dibujar();
    }

}


void mundo::clickRaton(int fila, int columna) {

    Casillas destino = table.getCasilla(fila, columna);
    caballoNegroarriba->setPosicion(fila, columna, destino.getX(), destino.getY());
    std::cout << "raton en: (" << fila << ", " << columna << ")" << std::endl;
    std::cout << "raton en: (" << destino.getX() << ", " << destino.getY() << ")" << std::endl;
}


