#include <windows.h>
#include<math.h>
#include <GL/glut.h>

static double s = 0.5;
const float DEG2RAD = 3.14159/180;
void display(void)
{
     glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
	 glClear(GL_COLOR_BUFFER_BIT);
	 glPolygonMode( GL_FRONT, GL_FILL );//glPolygonMode controls the interpretation of polygons for rasterization
     glColor3f(1.0, 0.0, 0.0 );

	glBegin(GL_POLYGON);
	for(int i=0; i < 360; i++)
	{
		 //convert degrees into radians
		float degInRad = i*DEG2RAD;
				glVertex2f(cos(degInRad)*s,sin(degInRad)*s);
	}
	glEnd();
glFlush();
}

void timer_function( int value)
{
    static bool flag = true ;
    static int count = 5;

    if ( count == 10 )
         flag=false;

    if (count == 0)
        flag=true;

    if (flag ) {
        s += 0.1;
        count++;
    }

    else {
        s -= 0.1;
        count--;
    }

    glutPostRedisplay();
    glutTimerFunc( 200,timer_function , 0);
}

int main ( int argc , char ** argv)
{
     glutInit( &argc , argv);
     glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
     glutInitWindowSize( 250,250);
     glutInitWindowPosition(100,100);
     glutCreateWindow("Solid Circle Animation");
     glutDisplayFunc ( display);
     glutTimerFunc (1, timer_function,0);
     glutMainLoop();
}
