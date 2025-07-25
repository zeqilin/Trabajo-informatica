
#pragma once
#include "Pieza.h"
#include "freeglut.h"
#include "ETSIDI.h"

class Torre: public Pieza
{
	
	ETSIDI::SpriteSequence sprite; 
public:
	Torre(int fila = 0, int columna = 0,Color col=Color::Negro) 
		:Pieza(fila, columna, col), sprite((col == Color::Blanco) ? "bin/imagenes/torre_blanca.png" : "bin/imagenes/torre_negra.png",1)
		{
			sprite.setCenter(0, 0);
		     sprite.setSize(1, 1);
	    }
	TipoPieza getTipo() const override { return TipoPieza::Torre; }

	void dibujar() override;
	bool movimientoValido(int filaDestino, int columnaDestino);
};

