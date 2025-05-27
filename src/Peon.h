#pragma once
#include "Coordenadas.h"
#include "ETSIDI.h"

class Peon {
    Coordenadas posicion{};
    ETSIDI::SpriteSequence sprite;

public:
    Peon(const char* rutaImagen = "bin/imagenes/peon_negro.png")
        : sprite(rutaImagen, 1) {
        sprite.setCenter(1, 1);
        sprite.setSize(1, 1);
    }

    void dibujar_peon();
    void setPosicion(Coordenadas pos) { posicion = pos; }
    Coordenadas getPosicion() const { return posicion; }
};




