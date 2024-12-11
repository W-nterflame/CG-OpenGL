#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>

int screenHeight = 480;
int screenWidth = 640;

class GLintPoint {
public:
	GLint x,y;
};

void myInit(void) {
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,1.0f,0.0f); // green color
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,(GLdouble)screenWidth,0,(GLdouble)screenHeight);
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
}

void myMouse(int button, int state, int x, int y) {

	static GLintPoint corner[2];
	static int numCorners = 0; // initial value is 0
	if  (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		corner[numCorners].x = x;
		corner[numCorners].y = screenHeight - y; //flip y-coordinate
		//note : because the y-value of the mouse position is the number of pixels
		// from the top of the screen window, so we draw the dot not at (x,y);
		// but at(x, screenHeight - y)

		numCorners++; // have another point

		if (numCorners == 2) {
			glRecti(corner[0].x, corner[0].y, corner[1].x, corner[1].y);
			numCorners = 0; // back to 0 corners
		}
	}

	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		glClear(GL_COLOR_BUFFER_BIT); // clear the window

	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(screenWidth,screenHeight); // set window size
	glutCreateWindow("Mouse Interaction");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse); // register mouse function
	myInit();
	glutMainLoop();
}
