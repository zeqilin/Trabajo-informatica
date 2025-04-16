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

	//Destructor virtual
	virtual ~pieza() {}

};
