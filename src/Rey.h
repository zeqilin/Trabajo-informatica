#pragma once
#include "pieza.h"
class Rey :
    public pieza
{
public:
    
    //Constructor del rey  
    Rey(int x, int y, bool color);

	//Implementaci�n del m�todo mover para el rey
	bool mover(int nuevaX, int nuevaY, pieza* tablero[8][8]) override;
};

