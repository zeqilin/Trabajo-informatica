#include "Caballo.h"
#include"freeglut.h"
#include<iostream>
void Caballo::dibujar() {
    
    glPushMatrix();
    glTranslated(posicion.getX(), posicion.getY(), 0.01);
    sprite.draw();
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
}
bool Caballo::movimientoValido(int filaDestino, int columnaDestino) {
    //posición actual del caballo
    int filaActual = posicion.getFila();
    int colActual = posicion.getColumna();

    int nf = std::abs(filaDestino - posicion.getFila()); //nf es el numero de filas que se movería el caballo
    int nc = std::abs(columnaDestino - posicion.getColumna());//nf es el numero de columnas que se movería el caballo

    return (nf == 2 && nc == 1) || (nf == 1 && nc == 2);//movimiento en L
}