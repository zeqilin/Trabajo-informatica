#pragma once
#include "Coordenadas.h"
#include "ETSIDI.h"
#include "Casillas.h"

class Peon {
    Casillas posicion{};
	ETSIDI::SpriteSequence sprite{ "bin/imagenes/peon_negro.png", 1 };

public:
	Peon(int fila = 0, int columna = 0)
		: posicion(fila, columna) {
		sprite.setCenter(0, 0);
		sprite.setSize(1, 1);
	}

    Casillas getPosicion() { return posicion; }

    void setPosicion(int fila, int columna, float x, float y) {
        posicion.setPosicionTablero(fila, columna);
        posicion.setCoordenadas(x, y);
    }

    void dibujar_peon();

};

