#include "Rey.h"
#include"freeglut.h"
void Rey::dibujar() {
    glPushMatrix();
    glTranslated(posicion.getX(), posicion.getY(), 0.01);
    sprite.draw();
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
}
bool Rey::movimientoValido(int filaDestino, int columnaDestino) {
    //posición actual del rey
    int filaActual = posicion.getFila();
    int colActual = posicion.getColumna();

    int nf = std::abs(filaDestino - filaActual);//nf es el numero de filas que se movería el rey, se usa abs para que el resultado sea siempre positivo
    int nc = std::abs(columnaDestino - colActual);//nc es el numero de columnas

    return (nf <= 1 && nc <= 1); //el rey se mueve 1 casilla en cualquier dirección
}