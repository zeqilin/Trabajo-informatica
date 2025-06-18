#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "tablero.h"
#include "Caballo.h"
#include "Peon.h"
#include "Alfil.h"
#include "Rey.h"
class mundo
{
    tablero table;
    Caballo caballo;
    Alfil alfil;
    Rey reyNegro;
    Peon peonesNegros[8];
public:
    mundo();
    void inicializa();
    void dibuja();
    void clickRaton(int fila, int columna);
};

