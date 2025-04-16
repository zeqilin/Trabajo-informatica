#pragma once

class pieza
{
protected:
	int x, y; //posici�n de la pieza en el tablero
	bool color; //True = blanca, False = negra

public:

	//Constructor
	pieza(int x, int y, bool color);

	//M�todos de acceso
	int getX();
	int getY();
	bool getColor();

	//M�todo virtual para mover la pieza, que ser� implementado en cada clase hija
	virtual bool mover(int nuevaX, int nuevaY, pieza* tablero[8][8]) = 0;

	//Destructor virtual
	virtual ~pieza() {}

};
