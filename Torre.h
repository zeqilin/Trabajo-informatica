#pragma once

#include "Coordenadas.h"
#include "Casillas.h"
#include "ETSIDI.h"

class Torre
{
	Casillas posicion{};
	ETSIDI::SpriteSequence sprite{ "bin/imagenes/torre_negra.png", 1 };
public:
	Torre(int fila = 0, int columna = 0)
		: posicion(fila, columna) {
		sprite.setCenter(0, 0);
		sprite.setSize(1, 1);
	}
	Casillas getPosicion() { return posicion; }
	void setPosicion(int fila, int columna, float x, float y) {
		posicion.setPosicionTablero(fila, columna);
		posicion.setCoordenadas(x, y);
	}

	void dibujar_torre();
};
