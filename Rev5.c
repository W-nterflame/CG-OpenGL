#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>

float rtrix, rtriy, rtriz;
float tquadx;
float tquady;
float CR = 1.0;
float CG = 1.0;
float CB = 1.0;


void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Reset the projection

    glPushMatrix();
    glTranslatef(0.0f, -5.0f, -6.0f); // Position for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a rectangle
        glColor3f(0.545f, 0.271f, 0.075f); // Brown color
        glVertex3f(-0.2f, 0.0f, 0.0f); // Bottom left
        glVertex3f(0.2f, 0.0f, 0.0f); // Bottom right
        glVertex3f(0.2f, 1.0f, 0.0f); // Top right
        glVertex3f(-0.2f, 1.0f, 0.0f); // Top left
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.0f, -6.0f); // Center the first triangle
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.5f, 0.0f); // Green color
        glVertex3f(0.0f, 0.0f, 0.0f); // Top vertex
        glVertex3f(-0.5f, -1.0f, 0.0f); // Left vertex
        glVertex3f(0.5f, -1.0f, 0.0f); // Right vertex
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -6.0f); // Move down for the second layer
    glScalef(1.4f, 1.2f, 1.2f); // Scale up
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.5f, 0.0f); // Green color
        glVertex3f(0.0f, 0.0f, 0.0f); // Top vertex
        glVertex3f(-0.5f, -1.0f, 0.0f); // Left vertex
        glVertex3f(0.5f, -1.0f, 0.0f); // Right vertex
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.2, -6.0f); // Move down for the third layer
    glScalef(1.8f, 1.6f, 1.0f); // Scale up
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.5f, 0.0f); // Green color
        glVertex3f(0.0f, 0.0f, 0.0f); // Top vertex
        glVertex3f(-0.5f, -0.8f, 0.0f); // Left vertex
        glVertex3f(0.5f, -0.8f, 0.0f); // Right vertex
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.0f, -2.4, -6.0f); // Move down for the third layer
    glScalef(2.0f, 2.0f, 1.0f); // Scale up
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.5f, 0.0f); // Green color
        glVertex3f(0.0f, 0.0f, 0.0f); // Top vertex
        glVertex3f(-0.5f, -0.8f, 0.0f); // Left vertex
        glVertex3f(0.5f, -0.8f, 0.0f); // Right vertex
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void myReshape(int w, int h) {
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (h == 0)
		gluPerspective(80,(float)w,1.0,5000);
	else
		gluPerspective(80,(float)w / (float)h,1.0,5000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(700,700);
	glutCreateWindow("Transformation");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);

	glutMainLoop();
return 0;
}
