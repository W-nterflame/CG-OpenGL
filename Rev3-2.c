#include <windows.h>
#include <GL/glut.h>

void displayT(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
		glVertex3f(0.0,0.5,0.0);
	glEnd();
	glFlush();
    glutSwapBuffers();
}
int main(int argc, char **argv) {

	glutInit(&argc, argv);
    glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Tutorial 03 - Triangle");
	glutDisplayFunc(displayT);
	glutMainLoop();
	return 1;
}

