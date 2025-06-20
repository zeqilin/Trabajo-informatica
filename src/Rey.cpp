#include "Rey.h"
#include"freeglut.h"
void Rey::dibujar() {
    glPushMatrix();
    glTranslated(posicion.getX(), posicion.getY(), 0.01);
    sprite.draw();
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
}
