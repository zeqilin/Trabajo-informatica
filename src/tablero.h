#pragma once
#include "Casillas.h"
#include "freeglut.h"
class tablero
{
	float tama�ocuadrado{1};
	Casillas casillas[8][8];
public:
	tablero();
	void dibujar_tablero();
};

