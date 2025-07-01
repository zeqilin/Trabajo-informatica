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
    Casillas c11 = table.getCasilla(2, 0);
    Casillas c12 = table.getCasilla(5, 0);
    Casillas c13 = table.getCasilla(2, 7);
    Casillas c14 = table.getCasilla(5, 7);
   // std::cout << "Caballo arriba pos: (" << c1.getX() << ", " << c1.getY() << ")\n";
    //std::cout << "Caballo abajo pos: (" << c2.getX() << ", " << c2.getY() << ")\n";

    // Asignar posiciones
   
  
    
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

   alfilNegroabajo = new Alfil(2, 0, Color::Negro);
    alfilNegroabajo->setPosicion(2, 0, c11.getX(), c11.getY());
   piezas.push_back(alfilNegroabajo);

    alfilNegroarriba = new Alfil(5, 0, Color::Negro);
   alfilNegroarriba->setPosicion(5, 0, c12.getX(), c12.getY());
   piezas.push_back(alfilNegroarriba);

    alfilBlancoarriba = new Alfil(5, 7, Color::Blanco);
   alfilBlancoarriba->setPosicion(5, 7, c14.getX(), c14.getY());
   piezas.push_back(alfilBlancoarriba);

   alfilBlancoabajo = new Alfil(2, 7, Color::Blanco);
   alfilBlancoabajo->setPosicion(2, 7, c13.getX(), c13.getY());
    piezas.push_back(alfilBlancoabajo);


    


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
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo.png").id);

    glDisable(GL_LIGHTING);
    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); glVertex3d(-5, -3, -0.1);   // Fondo más atrás en Z = -1
    glTexCoord2d(1, 1); glVertex3d(10, -3, -0.1);
    glTexCoord2d(1, 0); glVertex3d(10, 9, -0.1);
    glTexCoord2d(0, 0); glVertex3d(-5, 9, -0.1);
    glEnd();

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    
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
bool mundo::viaLibreTorre(int filaInicio, int colInicio, int filaDestino, int colDestino) {
    // La torre solo puede moverse en línea recta: horizontal o vertical
    bool movimientoHorizontal = (filaInicio == filaDestino);
    bool movimientoVertical = (colInicio == colDestino);

    if (!movimientoHorizontal && !movimientoVertical) {
        return false; // Movimiento inválido para torre
    }

    if (movimientoHorizontal) {// comprobar la fila menos el inicial y el final
        int columnaMin, columnaMax;
        if (colInicio < colDestino) {
            columnaMin = colInicio + 1;
            columnaMax = colDestino - 1;
        }
        else {
            columnaMin = colDestino + 1;
            columnaMax = colInicio - 1;
        }

        for (int c = columnaMin; c <= columnaMax; c++) {
            if (PiezaenPosicion(filaInicio, c) != nullptr) {
                return false; // Camino bloqueado
            }
        }
    }
    else if (movimientoVertical) {
        int filaMin, filaMax;
        if (filaInicio < filaDestino) {
            filaMin = filaInicio + 1;
            filaMax = filaDestino - 1;
        }
        else {
            filaMin = filaDestino + 1;
            filaMax = filaInicio - 1;
        }

        for (int f = filaMin; f <= filaMax; f++) {
            if (PiezaenPosicion(f, colInicio) != nullptr) {
                return false; // Camino bloqueado
            }
        }
    }

    return true; // Camino libre
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
            TipoPieza tipo = pieza->getTipo();
            int f = pieza->getPosicion().getFila();
            int c = pieza->getPosicion().getColumna();

            bool viaLibre = true;  // asumimos que sí hay vía libre

            if (tipo == TipoPieza::Torre) {
                viaLibre = viaLibreTorre(f, c, fila, columna);
            }
            if (viaLibre) {
                return true;  // amenaza válida con vía libre confirmada
            }
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
        // Primer clic: seleccionar pieza
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
            if (piezaSeleccionada->getTipo() == TipoPieza::Torre) {
                int filatorre = piezaSeleccionada->getPosicion().getFila();
                int coltorre = piezaSeleccionada->getPosicion().getColumna();
                if (!viaLibreTorre(filatorre, coltorre, fila, columna)) {
                    std::cout << "Movimiento inválido: la torre no tiene vía libre.\n";
                    piezaSeleccionada = nullptr;
                    return;
                }
            }
            Rey* reyActual = (TurnoActual == Color::Blanco) ? reyBlanco : reyNegro;
            bool reyEnJaqueAntes = estaAmenazado(reyActual->getPosicion().getFila(), reyActual->getPosicion().getColumna());

            // Guardar estado actual para poder revertir
            int filaAnt = piezaSeleccionada->getPosicion().getFila();
            int colAnt = piezaSeleccionada->getPosicion().getColumna();
            float xAnt = table.getCasilla(filaAnt, colAnt).getX();
            float yAnt = table.getCasilla(filaAnt, colAnt).getY();

            Pieza* objetivo = PiezaenPosicion(fila, columna);

            // Mover la pieza provisionalmente (sin borrar objetivo aún)
            piezaSeleccionada->setPosicion(fila, columna, destino.getX(), destino.getY());

            // Si hay objetivo, quitarlo provisionalmente para la comprobación
            if (objetivo && objetivo != piezaSeleccionada) {
                for (auto& p : piezas) {
                    if (p == objetivo) {
                        p = nullptr;
                    }
                }
            }

            bool reyEnJaqueDespues = estaAmenazado(reyActual->getPosicion().getFila(), reyActual->getPosicion().getColumna());

            if (reyEnJaqueAntes && reyEnJaqueDespues) {
                // Si estaba en jaque y sigue en jaque, movimiento inválido
                std::cout << "Movimiento inválido: el rey sigue en jaque.\n";
                // Revertir movimiento
                piezaSeleccionada->setPosicion(filaAnt, colAnt, xAnt, yAnt);

                // Restaurar pieza capturada si fue eliminada provisionalmente
                if (objetivo && objetivo != piezaSeleccionada) {
                    for (auto& p : piezas) {
                        if (p == nullptr) {
                            p = objetivo;
                            objetivo = nullptr;
                        }
                    }
                }

                piezaSeleccionada = nullptr;
                return; // Salir sin cambiar turno
            }

            // Si llegamos aquí, movimiento válido, eliminamos objetivo si hay
            if (objetivo && objetivo != piezaSeleccionada) {
                delete objetivo;
            }

            std::cout << "Pieza movida a (" << fila << ", " << columna << ")\n";

            aplicarGravedad();

            if (estaAmenazado(reyBlanco->getPosicion().getFila(), reyBlanco->getPosicion().getColumna()))
                std::cout << "\nrey blanco esta en jaque.\n\n";
            if (estaAmenazado(reyNegro->getPosicion().getFila(), reyNegro->getPosicion().getColumna()))
                std::cout << "\nrey negro esta en jaque.\n\n";
            

            if (!puedeReyEscapar(reyBlanco))
                std::cout << "\n¡Jaque mate al rey blanco!\n\n";
            if (!puedeReyEscapar(reyNegro))
                std::cout << "\n¡Jaque mate al rey negro!\n\n";

            // Cambiar turno
            TurnoActual = (TurnoActual == Color::Blanco) ? Color::Negro : Color::Blanco;
            piezaSeleccionada = nullptr;
        }
        else {
            std::cout << "Movimiento inválido para esta pieza.\n";
            piezaSeleccionada = nullptr;
        }
    }
}


