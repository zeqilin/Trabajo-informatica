#include "pieza.h"

//Constructor de la clase pieza
pieza::pieza(int x, int y, bool color) : x(x), y(y), color(color) {}

//Métodos de acceso
int pieza::getX() { return x; }
int pieza::getY() { return y; }
bool pieza::getColor() { return color; }