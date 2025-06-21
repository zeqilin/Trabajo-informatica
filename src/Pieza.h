#pragma once
#include "Casillas.h"

enum class Color { Blanco, Negro };

class Pieza {
protected:
    Casillas posicion;
    Color color;

public:
    Pieza(int fila, int columna, Color col) : posicion(fila, columna), color(col) {}


    virtual void dibujar() = 0;

    Casillas getPosicion() const { return posicion; }
    Color getColor() const { return color; }

    void setPosicion(int fila, int columna, float x, float y) {
        posicion.setPosicionTablero(fila, columna);
        posicion.setCoordenadas(x, y);
    }
    virtual bool movimientoValido(int filaDestino, int columnaDestino) = 0;
    
};