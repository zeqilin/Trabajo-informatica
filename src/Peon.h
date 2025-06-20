#pragma once
#include "Pieza.h"
#include "Coordenadas.h"
#include "ETSIDI.h"
#include "Casillas.h"

class Peon :public Pieza {
    ETSIDI::SpriteSequence sprite;

public:
	Peon(int fila = 0, int columna = 0, Color col = Color::Negro)
        : Pieza(fila, columna, col), sprite((col == Color::Blanco) ? "bin/imagenes/peon_blanco.png" : "bin/imagenes/peon_negro.png", 1)
    {
        sprite.setCenter(0, 0);
        sprite.setSize(1, 1);
    }
    /*void inicializarSprite(Color col) {
        if (col == Color::Blanco)
            sprite = ETSIDI::SpriteSequence("bin/imagenes/peon_blanco.png", 1);
        else
            sprite = ETSIDI::SpriteSequence("bin/imagenes/peon_negro.png", 1);

        sprite.setCenter(0, 0);
        sprite.setSize(1, 1);
    }*/
    void dibujar() override;
};
