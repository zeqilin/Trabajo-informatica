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

    //torreNegraabajo = new Torre(0, 0, Color::Negro);
   // torreNegraabajo->setPosicion(0, 0, c7.getX(), c7.getY());
    //piezas.push_back(torreNegraabajo);

   // torreNegraarriba = new Torre(7, 0, Color::Negro);
   // torreNegraarriba->setPosicion(0, 0, c8.getX(), c8.getY());
    //piezas.push_back(torreNegraarriba);



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
    
    caballoBlancoarriba = new Caballo(1, 7, Color::Blanco);
    caballoBlancoarriba->setPosicion(1, 7, c6.getX(), c6.getY());
    piezas.push_back(caballoBlancoarriba);

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
Rey* mundo::getRey(Color color) {
    if (color == Color::Blanco) return reyBlanco;
    else return reyNegro;
}
bool mundo::estaEnJaque(Color color) {
    Rey* rey = getRey(color);
    int filaRey = rey->getPosicion().getFila();
    int colRey = rey->getPosicion().getColumna();

    Color adversario = (color == Color::Blanco) ? Color::Negro : Color::Blanco;

    for (auto pieza : piezas) {
        if (pieza != nullptr && pieza->getColor() == adversario) {
            if (pieza->movimientoValido(filaRey, colRey)) {
                if (puedeCapturar(pieza, filaRey, colRey)) {
                    return true; //rey en jaque
                }
            }
        }
    }
    return false; // No está en jaque
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
            //guardar estado original
            int filaOriginal = piezaSeleccionada->getPosicion().getFila();
            int colOriginal = piezaSeleccionada->getPosicion().getColumna();
            float xOriginal = piezaSeleccionada->getPosicion().getX();
            float yOriginal = piezaSeleccionada->getPosicion().getY();

            Pieza* objetivo = PiezaenPosicion(fila, columna);
            bool esCaptura = puedeCapturar(piezaSeleccionada, fila, columna);
            bool objetivoEliminado = false;

            // Captura temporal
            if (esCaptura) {
                //busca el puntero objetivo (la pieza que se intenta capturar) dentro del vector piezas
                auto it = std::find(piezas.begin(), piezas.end(), objetivo);
                if (it != piezas.end()) {//verifica que se haya encontrado la pieza en el vector
                    *it = nullptr;  // quitarla del vector temporalmente
                    objetivoEliminado = true;
                }
            }
            // Mover temporalmente
            piezaSeleccionada->setPosicion(fila, columna, destino.getX(), destino.getY());

            // Verificar si el movimiento deja en jaque al propio rey
            if (estaEnJaque(TurnoActual)) {
                std::cout << "Movimiento invalido: dejarias a tu rey en jaque.\n";
                piezaSeleccionada->setPosicion(filaOriginal, colOriginal, xOriginal, yOriginal);

                if (objetivoEliminado && objetivo) {
                    auto it = std::find(piezas.begin(), piezas.end(), nullptr);
                    if (it != piezas.end()) {
                        *it = objetivo;  // restaurar
                    }
                }
            }
            else {
                // Movimiento valido
                if (esCaptura && objetivo) {
                    capturarPiezaEn(fila, columna);
                }
                std::cout << "Pieza movida a (" << fila << ", " << columna << ")\n";
                aplicarGravedad();
                // Cambiamos el turno después de mover
                TurnoActual = (TurnoActual == Color::Blanco) ? Color::Negro : Color::Blanco;

                if (estaEnJaque(TurnoActual)) {
                    std::cout << "JAQUE AL REY " << ((TurnoActual == Color::Blanco) ? "BLANCO" : "NEGRO") << "!\n";
                }
            }
        }
            
        else {
            std::cout << "Movimiento invalido para esta pieza.\n";
        }

        piezaSeleccionada = nullptr;  // Deseleccionamos después de mover
    }

}