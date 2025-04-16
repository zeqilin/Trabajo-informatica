#pragma once
#include "pieza.h"

class Alfil :
    public pieza
{
public:
   
    //Constructor del alfil
    Alfil(int x, int y, bool color);

	//Implementaci�n del m�todo mover para el alfil
	bool mover(int nuevaX, int nuevaY, pieza* tablero[8][8]) override;
};

