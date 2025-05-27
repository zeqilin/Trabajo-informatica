#include "Peon.h"
#include "freeglut.h"

void Peon::dibujar_peon() {
    glTranslated(casilla.getX(), casilla.getY(), 0.01);
    sprite.draw();
}