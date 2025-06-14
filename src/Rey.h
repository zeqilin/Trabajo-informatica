#pragma once
#include"Casillas.h"
#include"Coordenadas.h"
#include "ETSIDI.h" 
class Rey {
	Casillas posicion{};
	ETSIDI::SpriteSequence sprite;
public:
	Rey(const char* rutaImagen = "bin/imagenes/rey_negro.png", int fila = 0, int columna = 0)
		: sprite(rutaImagen, 1), posicion(fila, columna) {
		sprite.setCenter(0, 0);
		sprite.setSize(1, 1);
	}

	Casillas getPosicion() { return posicion; }

	void setPosicion(int fila, int columna, float x, float y) {
		posicion.setPosicionTablero(fila, columna);
		posicion.setCoordenadas(x, y);
	}

	void dibujar_rey();
};

