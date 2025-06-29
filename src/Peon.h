#pragma once
#include "Pieza.h"
#include "Coordenadas.h"
#include "ETSIDI.h"
#include "Casillas.h"
class Peon : public Pieza {
    static ETSIDI::SpriteSequence* spriteBlanco;
    static ETSIDI::SpriteSequence* spriteNegro;
    ETSIDI::SpriteSequence* sprite = nullptr;

public:
    Peon(int fila = 0, int columna = 0, Color col = Color::Negro)
        : Pieza(fila, columna, col)
    {
        if (col == Color::Blanco)
            sprite = spriteBlanco;
        else
            sprite = spriteNegro;
    }
    TipoPieza getTipo() const override { return TipoPieza::Peon; }

    static void cargarSprites();

    void dibujar() override;

    bool movimientoValido(int filaDestino, int columnaDestino);
};
