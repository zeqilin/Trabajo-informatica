#include "Peon.h"
#include "freeglut.h"

void Peon::dibujar_peon() {
    glPushMatrix();
    glTranslated(posicion.x, posicion.y , 0.01);
    sprite.draw();
    glPopMatrix();
}
