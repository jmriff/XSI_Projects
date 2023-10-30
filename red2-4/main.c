#include <GL/glut.h>
#include <math.h>

const GLdouble PI   = 3.1415926535898;
const GLint SIZE    = 30;
GLint circle_points = 1;

void display( void )
{
   glClearColor( 0.0, 0.0, 0.0, 0.0 );
   glClear( GL_COLOR_BUFFER_BIT );

   glColor3f( 1.0, 0.0, 0.0 );
   glPointSize(6);
   glLineWidth(2);

   circle_points = circle_points + 1;
   glBegin( GL_LINE_LOOP );
   for (int i = 0; i < circle_points; i++)
   {
      GLdouble angle = 2*PI*i/circle_points;
      glVertex2f(cos(angle)*SIZE, sin(angle)*SIZE);
   }
   glEnd();

   glBegin( GL_POINTS );
   for (int i = 0; i < circle_points; i++)
   {
      GLdouble angle = 2*PI*i/circle_points;
      glVertex2f(cos(angle)*SIZE, sin(angle)*SIZE);
   }
   glEnd();

   glFlush();
}

void keyboard( unsigned char key, int x, int y )
{
   if (key == 27 ) exit( 0 );
   if (key == 32 ) display();
}


void reshape (int w, int h)
{
   glViewport( 0, 0, (GLsizei) w, (GLsizei) h );
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity ();
   gluOrtho2D( -50.0, 50.0, -50.0, 50.0 );
   glMatrixMode( GL_MODELVIEW );
}




int main( int argC, char **argV)
{
   glutInit( &argC, argV );
   glutCreateWindow( "Look at me!  Look at me!  Look at me now!" );
   glutDisplayFunc( display );
   glutReshapeFunc( reshape );
   glutKeyboardFunc( keyboard );
   glutMainLoop();
   return 0;
}

