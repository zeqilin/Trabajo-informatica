#include "Torre.h"
#include "freeglut.h"



void Torre::dibujar_torre() {
	glPushMatrix();
	glTranslated(posicion.getX(), posicion.getY(), 0.01);
	sprite.draw();
}