#pragma once
#include "Pieza.h"
#include "ETSIDI.h"
#include "freeglut.h"

class Caballo : public Pieza {
    ETSIDI::SpriteSequence sprite;  // declarado sin inicializar

public:
    //en un principio se ha planteado poner el la diferenciacion de ruta de imagen fuera del constructor para que sea mas lejible pero ETSIDI::SpriteSequence no tiene constructor por defecto
    Caballo(int fila = 0, int columna = 0, Color col = Color::Negro)
        : Pieza(fila, columna, col),sprite((col == Color::Blanco) ? "bin/imagenes/caballo_blanco.png" : "bin/imagenes/caballo_negro.png", 1)
    {
        sprite.setCenter(0, 0);
        sprite.setSize(1, 1);
    }

    /*void inicializarSprite(Color col) {
        if (col == Color::Blanco)
            sprite = ETSIDI::SpriteSequence("bin/imagenes/caballo_blanco.png", 1);
        else
            sprite = ETSIDI::SpriteSequence("bin/imagenes/caballo_negro.png", 1);

        sprite.setCenter(0, 0);
        sprite.setSize(1, 1);
    }*/
    void dibujar() override;


};