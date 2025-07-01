#include "Alfil.h"
#include"freeglut.h"
#include <iostream>

void Alfil::dibujar() {
    glPushMatrix();
    glTranslated(posicion.getX(), posicion.getY(), 0.01);
    sprite.draw();
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
}

bool Alfil::movimientoValido(int filaDestino, int columnaDestino) {
    //posición actual de la torre
    int filaActual = posicion.getFila();
    int colActual = posicion.getColumna();

    int nf = std::abs(filaDestino - filaActual);//nf es el numero de filas que se movería la torre, se usa abs para que el resultado sea siempre positivo
    int nc = std::abs(columnaDestino - colActual);//nc es el numero de columnas

    return (nf==nc && nf>=1 ); //el alfil se mueve solo en diagonal
}

