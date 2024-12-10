#include <windows.h>
#include <GL/glut.h>
#include<math.h>

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int circle_points = 100;

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    double angle = 2*  3.14/100 ;
    glPolygonMode( GL_FRONT, GL_FILL );
    glColor3f(1.0, 0.0, 0.0 );
    glBegin(GL_POLYGON);
    double angle1 = 0.0;
    glVertex2d( 0.7 * cos(0.0) , 0.7 * sin(0.0));
    for (int i = 0; i < circle_points; i++)
    {
        glVertex2d(0.7 * cos(angle1), 0.7 *sin(angle1));
        angle1 += angle ;
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutCreateWindow("Vertex, Primitive & Color");
   glutInitWindowSize(400, 400);
   glutInitWindowPosition(50, 50);
   glutDisplayFunc(draw);
   initGL();
   glutMainLoop();
   return 0;
}
