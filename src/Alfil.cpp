#include "Alfil.h"
#include"freeglut.h"


void Alfil::dibujar_alfil() {
	glPushMatrix();
	glTranslated(posicion.getX(), posicion.getY(), 0.01);
	sprite.draw();
}

