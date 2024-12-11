#include <Windows.h>
#include <GL/glut.h>
#include <GL/gl.h>

	GLint x1 = 220;
	GLint y1 = 200;
	GLint x2 = 300;
	GLint y2 = 300;

void myInit(void) {
	glClearColor(1.0,1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640.0,0,480.0);
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(10.0);
	glColor3f(0.0f,0.0f,0.0f);

	glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glFlush();
}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {

	switch(theKey) {
	case'r' :
		x1 += 10;
		x2 += 10;
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

void specialKey(int key, int x, int y){
    switch(key){

        case GLUT_KEY_UP:
            if(corY < 0.97)
                corY += 0.01;
        break;

        case GLUT_KEY_DOWN:
            if(corY > -0.97)
                corY -=0.01;
        break;

        case GLUT_KEY_LEFT:
            if(corX > -0.5)
                corX -=0.01;
        break;

        case GLUT_KEY_RIGHT:
            if(corX <  0.5)
                corX +=0.01;
        break;
    }

    glutPostRedisplay();

}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Keyboard Interaction");
	glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(specialKey);
	myInit();
	glutMainLoop();

    return 0;
}
