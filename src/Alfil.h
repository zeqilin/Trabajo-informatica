
#pragma once
#include "Pieza.h"
#include "freeglut.h"
#include "ETSIDI.h"

class Alfil : public Pieza
{

	ETSIDI::SpriteSequence sprite;
public:
	Alfil(int fila = 0, int columna = 0, Color col = Color::Negro)
		:Pieza(fila, columna, col), sprite((col == Color::Blanco) ? "bin/imagenes/AlfilB.png" : "bin/imagenes/AlfilN.png", 1)
	{
		sprite.setCenter(0, 0);
		sprite.setSize(1, 1);
	}
	//TipoPieza getTipo() const override { return TipoPieza::Alfil; }

	void dibujar() override;
	bool movimientoValido(int filaDestino, int columnaDestino);
};