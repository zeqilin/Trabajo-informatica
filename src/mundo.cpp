#include "mundo.h"
#include <iostream>
mundo::mundo() {
    inicializa();
}

void mundo::inicializa() {
    Peon::cargarSprites();
    TurnoActual = Color::Blanco;
    Casillas c1 = table.getCasilla(6, 0); 
    Casillas c2 = table.getCasilla(1, 0); 
    Casillas c3 = table.getCasilla(3, 0);
    Casillas c4 = table.getCasilla(3, 7);
    Casillas c5 = table.getCasilla(6, 7);
    Casillas c6 = table.getCasilla(1, 7);
    Casillas c7 = table.getCasilla(0, 0);
    Casillas c8 = table.getCasilla(7, 0);
    Casillas c9 = table.getCasilla(0, 7);
    Casillas c10 = table.getCasilla(7, 7);
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

    torreNegraabajo = new Torre(0, 0, Color::Negro);
   torreNegraabajo->setPosicion(0, 0, c7.getX(), c7.getY());
    piezas.push_back(torreNegraabajo);

   torreNegraarriba = new Torre(7, 0, Color::Negro);
    torreNegraarriba->setPosicion(7, 0, c8.getX(), c8.getY());
    piezas.push_back(torreNegraarriba);

    torreBlancaabajo = new Torre(0, 7, Color::Blanco);
    torreBlancaabajo->setPosicion(0, 7, c9.getX(), c9.getY());
    piezas.push_back(torreBlancaabajo);

    torreBlancaarriba = new Torre(7, 7, Color::Blanco);
    torreBlancaarriba->setPosicion(7, 7, c10.getX(), c10.getY());
    piezas.push_back(torreBlancaarriba);

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

    caballoBlancoarriba = new Caballo(6, 7, Color::Blanco);
    caballoBlancoarriba->setPosicion(6, 7, c5.getX(), c5.getY());
    piezas.push_back(caballoBlancoarriba);
    
    caballoBlancoabajo = new Caballo(1, 7, Color::Blanco);
    caballoBlancoabajo->setPosicion(1, 7, c6.getX(), c6.getY());
    piezas.push_back(caballoBlancoabajo);

    //std::cout << "Caballo1 en: (" << caballoNegroarriba->getPosicion().getFila() << "," << caballoNegroarriba->getPosicion().getColumna() << ")\n";
    //std::cout << "Caballo2 en: (" << caballoNegroabajo->getPosicion().getFila() << "," << caballoNegroabajo->getPosicion().getColumna() << ")\n";


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
        if(pieza!=nullptr)
        pieza->dibujar();
    }

}
//busca en el vector de pieza si hay pieza con la posicion entrante a la función( para la seleccion de pieza,creo que se podria usar para la captura tambien despues)
//en un principio se ha planteado usar bool pero no dejaria actuar sobre la pieza despues para moverla
Pieza* mundo::PiezaenPosicion(int fila, int columna) {
    for (auto pieza : piezas) {
        if (pieza != nullptr&&pieza->getPosicion().getFila() == fila &&
            pieza->getPosicion().getColumna() == columna) {
            return pieza;
        }
    }
    return nullptr; // No hay pieza en esa casilla
}

void mundo::capturarPiezaEn(int fila, int columna) {
    Pieza* objetivo = PiezaenPosicion(fila, columna);

    // Si hay una pieza en esa posición y no es la misma que la que se está moviendo
    if (objetivo && objetivo != piezaSeleccionada) {
        std::cout << "Pieza capturada en (" << fila << ", " << columna << ")\n";

        // Buscar y eliminar del vector
        for (int i = 0; i < piezas.size(); i++) {
            if (piezas[i] == objetivo) {
                delete objetivo;
                piezas[i] = nullptr;

            }
        }
    }
}
bool mundo::puedeCapturar(Pieza* atacante, int fila, int columna) {
    Pieza* objetivo = PiezaenPosicion(fila, columna);

    if (atacante != nullptr && objetivo != nullptr && atacante != objetivo && atacante->movimientoValido(fila, columna)) {
        return true;
    }
    else {
        return false;
    }
}
bool mundo::estaAmenazado(int fila, int columna) {

    for (auto pieza : piezas) {
        if (pieza != nullptr && puedeCapturar(pieza, fila, columna)) {
            return true;
        }
    }

    return false;
}
bool mundo::puedeReyEscapar(Rey* rey) {
    int filaActual = rey->getPosicion().getFila();
    int colActual = rey->getPosicion().getColumna();

    for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8; col++) {
            if (rey->movimientoValido(fila, col)) {

                // Simulamos el movimiento
                rey->setPosicion(fila, col, table.getCasilla(fila, col).getX(), table.getCasilla(fila, col).getY());

                bool enJaque = estaAmenazado(fila, col);

                // Restauramos la posición original del rey
                rey->setPosicion(filaActual, colActual, table.getCasilla(filaActual, colActual).getX(), table.getCasilla(filaActual, colActual).getY());

                if (!enJaque) {
                    std::cout << "El rey puede escapar a (" << fila << ", " << col << ")\n";
                    return true;
                }
                else {
                    std::cout << "Casilla (" << fila << ", " << col << ") está amenazada.\n";
                }
            }
        }
    }

    std::cout << "El rey NO puede escapar.\n";
    return false;
}
void mundo::aplicarGravedad() {
    for (int col = 0; col < 8; col++) {
        std::vector<Pieza*> piezasEnColumna;

        // Meter piezas no nulas de la columna en el vector
        for (int fila = 0; fila < 8; fila++) {
            Pieza* p = PiezaenPosicion(fila, col);
            if (p != nullptr) {
                piezasEnColumna.push_back(p);
            }
        }

        // Reubicar las piezas desde la fila 0 hacia arriba 
        for (int i = 0; i < piezasEnColumna.size(); i++) {
            int nuevaFila = i; // La fila más baja disponible
            Casillas nuevaCasilla = table.getCasilla(nuevaFila, col);
            piezasEnColumna[i]->setPosicion(nuevaFila, col, nuevaCasilla.getX(), nuevaCasilla.getY());
        }
    }
}


void mundo::clickRaton(int fila, int columna) {

    Casillas destino = table.getCasilla(fila, columna);
    if (piezaSeleccionada == nullptr) {
        // Primer clic: seleccionar
        piezaSeleccionada = PiezaenPosicion(fila, columna);
        if (piezaSeleccionada) {
            if (piezaSeleccionada->getColor() == TurnoActual) {
                std::cout << "Pieza seleccionada en (" << fila << ", " << columna << ")\n";
            }
            else {
                std::cout << "No es tu turno\n";
                piezaSeleccionada = nullptr;
            }
        }
        else {
            std::cout << "No hay pieza en esa casilla\n";
        }
    }
    else {
        // Segundo clic: intentar mover
        if (piezaSeleccionada->movimientoValido(fila, columna)) {

            if (puedeCapturar(piezaSeleccionada, fila, columna)) {
                capturarPiezaEn(fila, columna);
            }
            piezaSeleccionada->setPosicion(fila, columna, destino.getX(), destino.getY());
            std::cout << "Pieza movida a (" << fila << ", " << columna << ")\n";
            // Cambiamos el turno después de mover
            aplicarGravedad();
            if (estaAmenazado(reyNegro->getPosicion().getFila(), reyNegro->getPosicion().getColumna()))
                std::cout << "rey negro está en jaque.\n";
            if (estaAmenazado(reyBlanco->getPosicion().getFila(), reyBlanco->getPosicion().getColumna()))
                std::cout << "rey blanco está en jaque.\n";
            if (!puedeReyEscapar(reyBlanco)) {
                std::cout << "¡Jaque mate al rey blanco!\n";
            }
            if (!puedeReyEscapar(reyNegro)) {
                std::cout << "¡Jaque mate al rey Negro!\n";
            }
            TurnoActual = (TurnoActual == Color::Blanco) ? Color::Negro : Color::Blanco;
            
        }
        else {
            std::cout << "Movimiento inválido para esta pieza.\n";
        }

        piezaSeleccionada = nullptr;  // Deseleccionamos después de mover
    }

}

