#pragma once
#include "Caballo.h"
#include "Peon.h"
#include "tablero.h"

enum TipoPieza { NINGUNA, CABALLO, PEON_NEGRO, PEON_BLANCO };

class moverpiezas {
    TipoPieza piezaSeleccionada = NINGUNA;
    int peonSeleccionado = -1;

    Caballo* caballo;
    Peon* peonesNegros;
    Peon* peonesBlancos;
    tablero* table;

public:
    moverpiezas(Caballo* c, Peon* pn, Peon* pb, tablero* t)
        : caballo(c), peonesNegros(pn), peonesBlancos(pb), table(t) {
    }

    void manejarTecla(unsigned char key);

private:
    void moverCaballo(unsigned char key);
    void moverPeon(unsigned char key);
};
