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
        sprite.setCenter(0, 0);
        sprite.setSize(1, 1);
    }

    void setCasilla(const Casillas& casilla) {
        posicion.x = casilla.getX();
        posicion.y = casilla.getY();
        sprite.setPos(posicion.x, posicion.y);
    }

    void dibujar_peon();

};




