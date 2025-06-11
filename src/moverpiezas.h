#pragma once
#include "Caballo.h"
#include "Peon.h"
#include "Alfil.h"
#include "tablero.h"

enum TipoPieza { NINGUNA, CABALLO, PEON_NEGRO, PEON_BLANCO,ALFIL };

class moverpiezas {
    TipoPieza piezaSeleccionada = NINGUNA;
    int peonSeleccionado = -1;

    Caballo* caballo;
    Peon* peonesNegros;
    Peon* peonesBlancos;
    Alfil* AlfilN;
    tablero* table;

public:
    moverpiezas(Caballo* c, Peon* pn, Peon* pb, tablero* t, Alfil* al)
        : caballo(c), peonesNegros(pn), peonesBlancos(pb), table(t),AlfilN(al) {
    }

    void manejarTecla(unsigned char key);

private:
    void moverCaballo(unsigned char key);
    void moverPeon(unsigned char key);
    void moverAlfil(unsigned char key);
};
