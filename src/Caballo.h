#pragma once
#include"Coordenadas.h"
#include "ETSIDI.h" 
class Caballo
{
	Coordenadas posicion{};
	ETSIDI::SpriteSequence sprite{ "bin/imagenes/caballo_negro.png", 1 };
public:
	
	Caballo() {
		sprite.setCenter(1,0);
		sprite.setSize(1, 1);
	}
	void dibujar_caballo();
};

