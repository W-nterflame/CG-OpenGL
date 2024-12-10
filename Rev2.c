#include <windows.h>
#include <GL/glut.h>

void display(void)
{
    glColor3f(1.0,0.0,0.0);
    gluOrtho2D(0.0,100.0,0.0,150.0);
    glBegin(GL_LINES);

    for (int i = 10 ; i <= 100 ; i += 10) {
        glVertex2i(10,i);
        glVertex2i(50,i);
    }

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
