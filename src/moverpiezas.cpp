#include "moverpiezas.h"
void moverpiezas::manejarTecla(unsigned char key) {
    if (key == 'c') {
        piezaSeleccionada = CABALLO;
        peonSeleccionado = -1;
    }
    else if (key >= '1' && key <= '8') {
        piezaSeleccionada = PEON_NEGRO;
        peonSeleccionado = key - '1';
    }
    else if (key >= '!' && key <= '(') {
        piezaSeleccionada = PEON_BLANCO;
        peonSeleccionado = key - '!';
    }
    else if (key == 27) {
        piezaSeleccionada = NINGUNA;
        peonSeleccionado = -1;
    }
    else if (key == 'w' || key == 'a' || key == 's' || key == 'd') {
        if (piezaSeleccionada == CABALLO)
            moverCaballo(key);
        else if (piezaSeleccionada == PEON_NEGRO || piezaSeleccionada == PEON_BLANCO)
            moverPeon(key);
    }
}

void moverpiezas::moverCaballo(unsigned char key) {
    int fila = caballo->getPosicion().getFila();
    int col = caballo->getPosicion().getColumna();

    if (key == 'w') fila += 1;
    if (key == 's') fila -= 1;
    if (key == 'a') col -= 1;
    if (key == 'd') col += 1;

    Casillas destino = table->getCasilla(fila, col);
    caballo->setPosicion(fila, col, destino.getX(), destino.getY());
}

void moverpiezas::moverPeon(unsigned char key) {
    if (peonSeleccionado < 0 || peonSeleccionado >= 8) return;

    Peon& peon = (piezaSeleccionada == PEON_NEGRO) ? peonesNegros[peonSeleccionado] : peonesBlancos[peonSeleccionado];
    Coordenadas pos = peon.getPosicion();

    if (key == 'w') pos.y += 1;
    if (key == 's') pos.y -= 1;
    if (key == 'a') pos.x -= 1;
    if (key == 'd') pos.x += 1;

    Casillas destino = table->getCasilla((int)pos.y, (int)pos.x);
    peon.setCasilla(destino);
}
void moverpiezas::moverAlfil(unsigned char key) {
    int fila = AlfilN->getPosicion().getFila();
    int col = AlfilN->getPosicion().getColumna();
    if (key == 'w'&& key=='d'&& fila<0 && col<8) {
       
            fila += 1;
            col += 1;
            Casillas destino = table->getCasilla(fila, col);
            AlfilN->setPosicion(fila,col, destino.getX(), destino.getY());
    }
}