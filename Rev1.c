#include <windows.h>
#include <GL/glut.h>

void display(void)
{
    glBegin(GL_LINES);
    glVertex2f(0.0,0.0);
    glVertex2f(0.75,0.75);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutCreateWindow("Nama");
    glutInitWindowSize(400,400);
    glutInitWindowPosition(50,50);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
