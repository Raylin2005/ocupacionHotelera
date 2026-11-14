#include <GL/glut.h>
int ocupacion[7] = {65, 72, 80, 95, 88, 60, 55};

// Función de dibujo
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Dibujar los ejes
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINES);
        
        // Eje horizontal
        glVertex2f(1, 1);
        glVertex2f(100, 1);

        // Eje vertical
        glVertex2f(1, 1);
        glVertex2f(1, 100);

    glEnd();
    
    //Dibujar las barras
    for (int i = 0; i < 7; i++) {
    	//seleccionar el color segun la ocupacion
    	if (ocupacion[i] < 70) {
    		glColor3f(0, 1, 0);
		}
		else if(ocupacion[i] < 90) {
			glColor3f(1, 0.6, 0);
		}
		else {
			glColor3f(1, 0, 0);
		}
		//calcular la posision horizontal
		float x = 10 + i * 12;
		
		//dibujar el rectangulo
		glBegin(GL_QUADS);
		 
		 glVertex2f(x, 1);
		 glVertex2f(x + 8, 1);
		 glVertex2f(x + 8, ocupacion[i]);
		 glVertex2f(x, ocupacion[i]);
		
		glEnd();
		
	}

    glutSwapBuffers();
}


// Configuración de la ventana y las coordenadas
void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 100, 0, 110);

    glMatrixMode(GL_MODELVIEW);
}

// Función principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Practica OpenGL");

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}

