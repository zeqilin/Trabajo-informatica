#pragma once

class pieza
{
protected:
	int x, y; //posición de la pieza en el tablero
	bool color; //True = blanca, False = negra

public:

	//Constructor
	pieza(int x, int y, bool color);

	//Métodos de acceso
	int getX();
	int getY();
	bool getColor();

	//Método virtual para mover la pieza, que será implementado en cada clase hija
	virtual bool mover(int nuevaX, int nuevaY, pieza* tablero[8][8]) = 0;

	//Destructor virtual
	virtual ~pieza() {}

};
