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

    //creo esta función para elegir la posición de mi peón
    void setPosicion(Coordenadas pos) {
        posicion = pos;
    }
};

