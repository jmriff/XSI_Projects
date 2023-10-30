#include <GL/glut.h>



void display( void )
{
   glClearColor( 0.1, 0.1, 0.1, 0.0 );
   glClear( GL_COLOR_BUFFER_BIT );

   glColor3f( 0.0, 1.0, 0.0 );

   glBegin( GL_TRIANGLES );
   glVertex2f( 0.0, 0.0 );
   glVertex2f( 15.0, 30.0 );
   glVertex2f( 30.0, 0.0 );
   glVertex2f( 40.0,-10.0 );
   glVertex2f( 55.0, 20.0 );
   glVertex2f( 70.0,-10.0 );
   glEnd();

   glFlush();
}

void keyboard( unsigned char key, int x, int y )
{
   if (key == 27 ) exit( 0 );
}


void reshape (int w, int h)
{
   glViewport( 0, 0, (GLsizei) w, (GLsizei) h );
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity ();
   gluOrtho2D( -20.0, 75, -20.0, 75 );
   glMatrixMode( GL_MODELVIEW );
}




int main( int argC, char **argV)
{
   glutInit( &argC, argV );
   glutCreateWindow( "Hello Everybody!" );
   glutDisplayFunc( display );
   glutReshapeFunc( reshape );
   glutKeyboardFunc( keyboard );
   glutMainLoop();
   return 0;
}

