#pragma once
class Casillas
{
    int fila;
    int columna;
    float x;
    float y;

public:
    //constructor
    Casillas(int f = 0, int c = 0, float x = 0, float y = 0)
        : fila(f), columna(c), x(x), y(y) {}

    // Getters
    int getFila() const { return fila; }
    int getColumna() const { return columna; }
    float getX() const { return x; }
    float getY() const { return y; }

    // Setters
    void setPosicionTablero(int f, int c) { fila = f; columna = c; }
    void setCoordenadas(float x_, float y_) { x = x_; y = y_; }
};

