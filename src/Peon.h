#pragma once
#include "Coordenadas.h"
#include "ETSIDI.h"
#include "Casillas.h"

class Peon {
    Coordenadas posicion{};
    ETSIDI::SpriteSequence sprite;
    Casillas casilla;

public:
    Peon(const char* rutaImagen = "bin/imagenes/peon_negro.png")
        : sprite(rutaImagen, 1), casilla(0, 0, 0.0f, 0.0f) {
        sprite.setCenter(1, 1);
        sprite.setSize(1, 1);
    }

    void setCasilla(const Casillas& casilla) {
        posicion.x = casilla.getX() + 1;
        posicion.y = casilla.getY() + 1;
        sprite.setPos(posicion.x, posicion.y);
    }

    void dibujar_peon();

};




