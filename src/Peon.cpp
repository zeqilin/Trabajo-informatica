#include "Peon.h"
#include "freeglut.h"

void Peon::dibujar_peon() {
	glPushMatrix();
	glTranslated(posicion.getX(), posicion.getY(), 0.01);
	sprite.draw();
}