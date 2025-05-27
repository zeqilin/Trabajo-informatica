#pragma once
#include"Casillas.h"
#include"Coordenadas.h"
#include "ETSIDI.h" 
class Caballo
{
	Casillas posicion{};
	ETSIDI::SpriteSequence sprite{ "bin/imagenes/caballo_negro.png", 1 };
public:
	Caballo(int fila = 0, int columna = 0)
		: posicion(fila, columna) {
		sprite.setCenter(0, 0);
		sprite.setSize(1, 1);
	}
	Casillas getPosicion() { return posicion; }
	void setPosicion(int fila, int columna, float x, float y) {
		posicion.setPosicionTablero(fila, columna);
		posicion.setCoordenadas(x, y);
	}


	void dibujar_caballo();
};