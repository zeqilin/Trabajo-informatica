#include "Rey.h"
#include"freeglut.h"
void Rey::dibujar_rey() {
	glPushMatrix();
	glTranslated(posicion.getX(), posicion.getY(), 0.01);
	sprite.draw();
}