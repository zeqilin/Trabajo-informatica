#include "freeglut.h"
#include "ETSIDI.h"
#include "mundo.h"
#include<iostream>
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void ratonClick(int boton, int estado, int x, int y);

mundo Mundo;

int main(int argc, char* argv[])
{
	
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	glClearColor(0.8f, 0.8f, 0.8f, 1.0f); // pongo el fondo gris claro para poder visualizar bien todas las piezas

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(ratonClick);

	//POSIBLE INICIALIZACION

	//pasarle el control a GLUT,que llamara a los callbacks
	
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//funciones de dibujo
	gluLookAt(4, 4, 12,  // posicion del ojo
		4, 4, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);

	Mundo.dibuja();
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	
	//mover->manejarTecla(key);

	/*int filaActual = caballo.getPosicion().getFila();
	int columnaActual = caballo.getPosicion().getColumna();

	
	int nuevaFila = filaActual;
	int nuevaColumna = columnaActual;

	switch (key) {
	case 'w': nuevaFila += 1; break; // arriba
	case 's': nuevaFila -= 1; break; // abajo
	case 'a': nuevaColumna -= 1; break; // izquierda
	case 'd': nuevaColumna += 1; break; // derecha
	default: return;
	}

	
	//recibir información del casilla destino	
	Casillas destino = table.getCasilla(nuevaFila, nuevaColumna);

			// Actualizar posición lógica y visual del caballo
	caballo.setPosicion(nuevaFila, nuevaColumna, destino.getX(), destino.getY());*/
	

	glutPostRedisplay();

}
void ratonClick(int boton, int estado, int x, int y) {
	if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
		int ancho =800;
		int alto = 600;
		float x_opengl = static_cast<float>(x) / ancho * 8.0f;
		float y_opengl = static_cast<float>(alto - y) / alto * 8.0f;

		int columna = static_cast<int>(x_opengl);
		int fila = static_cast<int>(y_opengl);
		
		Mundo.clickRaton(fila, columna);
		
		glutPostRedisplay();
	}

}

void OnTimer(int value)
{
	//poner aqui el código de animacion

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}


