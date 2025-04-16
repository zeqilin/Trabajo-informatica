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

	//Destructor virtual
	virtual ~pieza() {}

};
