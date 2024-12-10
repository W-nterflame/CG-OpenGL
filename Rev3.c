#include <windows.h>
#include <GL/glut.h>
#include <math.h>

const float DEG2RAD = 3.14159/180.0;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
}

float xradius=0.3,yradius=0.3;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
	for(int i=0; i < 360; i++)
	{
		float degInRad = i*DEG2RAD;
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(cos(degInRad)*xradius,sin(degInRad)*yradius);
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);          
   glutCreateWindow("Vertex, Primitive & Color");  
   glutInitWindowSize(400, 400);   
   glutInitWindowPosition(50, 50); 
   glutDisplayFunc(display);       
   initGL();                       
   glutMainLoop();                 
   return 0;
}
