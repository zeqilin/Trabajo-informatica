#pragma once
#include "Coordenadas.h"
#include "ETSIDI.h"

class Peon {
    Coordenadas posicion{};
    ETSIDI::SpriteSequence sprite{ "bin/imagenes/peon_negro.png", 1 };

public:
    Peon() {
        sprite.setCenter(1, 1);
        sprite.setSize(1, 1); 
    }

    void dibujar_peon();

    //creo esta función para elegir la posición de mi peón
    void setPosicion(Coordenadas pos) {
        posicion = pos;
    }
};

