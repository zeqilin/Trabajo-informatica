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