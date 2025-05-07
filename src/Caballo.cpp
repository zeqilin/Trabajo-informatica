#include "Caballo.h"
#include"freeglut.h"
void Caballo::dibujar_caballo() {
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 1);
	sprite.draw();
}