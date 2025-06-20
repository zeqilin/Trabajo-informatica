#include "Peon.h"
#include "freeglut.h"

void Peon::dibujar() {
    glPushMatrix();
    glTranslated(posicion.getX(), posicion.getY(), 0.01);
    sprite.draw();
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
}