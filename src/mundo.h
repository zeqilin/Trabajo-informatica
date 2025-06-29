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
    Caballo* caballoBlancoarriba;
    Caballo* caballoBlancoabajo;
    Color TurnoActual;
    Torre* torreNegraabajo;
    Torre* torreNegraarriba;
    Torre* torreBlancaabajo;
    Torre* torreBlancaarriba;

public:
    mundo();
    void inicializa();
    void dibuja();
    void clickRaton(int fila, int columna);
    Pieza* PiezaenPosicion(int fila, int columna);
    void capturarPiezaEn(int fila, int columna);
    bool puedeCapturar(Pieza* atacante, int fila, int columna);
    void aplicarGravedad();
    bool estaAmenazado(int fila, int columna);
    bool puedeReyEscapar(Rey* rey);
    bool viaLibreTorre(int filaInicio, int colInicio, int filaDestino, int colDestino);
};

