#pragma once
#include<vector>
#include "freeglut.h"
#include "ETSIDI.h"
#include "tablero.h"
#include "Caballo.h"
#include "Peon.h"
#include "Alfil.h"
#include "Rey.h"
#include "Torre.h"
using std::vector;
class mundo
{
    vector<Pieza*> piezas;
    Pieza* piezaSeleccionada ;
    tablero table;
    //Caballo caballo;
    Alfil alfil;
    Rey* reyNegro;
    Rey* reyBlanco;
    Peon* peonesNegros[8];
    Peon* peonesBlancos[8];
    Caballo* caballoNegroarriba;
    Caballo* caballoNegroabajo;
    Color TurnoActual;
    Torre torre;

public:
    mundo();
    void inicializa();
    void dibuja();
    void clickRaton(int fila, int columna);
    Pieza* PiezaenPosicion(int fila, int columna);
};

