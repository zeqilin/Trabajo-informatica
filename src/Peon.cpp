#include "Peon.h"
#include "freeglut.h"

ETSIDI::SpriteSequence* Peon::spriteBlanco = nullptr;
ETSIDI::SpriteSequence* Peon::spriteNegro = nullptr;

void Peon::cargarSprites() {
    spriteBlanco = new ETSIDI::SpriteSequence("bin/imagenes/peon_blanco.png", 1);
    spriteNegro = new ETSIDI::SpriteSequence("bin/imagenes/peon_negro.png", 1);

    spriteBlanco->setCenter(0, 0);
    spriteBlanco->setSize(1, 1);

    spriteNegro->setCenter(0, 0);
    spriteNegro->setSize(1, 1);
}

void Peon::dibujar() {
    glPushMatrix();
    glTranslated(posicion.getX(), posicion.getY(), 0.01);
    if (sprite)
        sprite->draw();
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
}
bool Peon::movimientoValido(int filaDestino, int columnaDestino) {
    //posición actual del peón
    int filaActual = posicion.getFila();
    int colActual = posicion.getColumna();

    int dir = (color == Color::Blanco) ? -1 : 1;
    int colInicial = (color == Color::Blanco) ? 6 : 1;

    //Movimiento normal
    if (columnaDestino == colActual + dir && filaDestino == filaActual) {
        return true;
    }

    //Avance inicial
    if (colActual == colInicial && columnaDestino == colActual + 2 * dir && filaDestino == filaActual) {
        return true;
    }

    //Captura diagonal
    if (columnaDestino == colActual + dir && abs(filaDestino - filaActual) == 1) {
        return true;
    }
    return false;
    
}
