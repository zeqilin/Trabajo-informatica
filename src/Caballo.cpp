#include "Caballo.h"
#include"freeglut.h"
void Caballo::dibujar_caballo() {
	glPushMatrix();
	glTranslated(posicion.getX(), posicion.getY(), 0.01);
	sprite.draw();
}