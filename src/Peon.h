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

    //creo esta funci�n para elegir la posici�n de mi pe�n
    void setPosicion(Coordenadas pos) {
        posicion = pos;
    }
};

