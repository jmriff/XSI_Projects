#include <GL/gl.h>
#include <GL/glut.h>

void drawOneLine( GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2 )
{
   glBegin( GL_LINES );
   glVertex2f( x1, y1 );
   glVertex2f( x2, y2 );
   glEnd();
}

void init( void )
{
   glClearColor( 0.0, 0.0, 0.0, 0.0 );
   glShadeModel( GL_FLAT );
}

void display ( void )
{
   int i;

   glClear (GL_COLOR_BUFFER_BIT );

   /* Select white for all lines */
   glColor3f( 1.0, 1.0, 1.0 );

   /* in 1st row, 3 lines, each with a different stipple */
   glEnable( GL_LINE_STIPPLE );

   glLineStipple( 1, 0x0101 ); /* dotted */
   glLineWidth( 1.0 );
   drawOneLine( 50.0, 125.0, 150.0, 125.0 );

   glLineStipple( 4, 0x00FF ); /* dashed */
   glLineWidth( 4.0 );
   drawOneLine( 150.0, 125.0, 550.0, 125.0 );

   glLineStipple( 8, 0x1c47 ); /* dash/dot/dash */
   glLineWidth( 8 );
   drawOneLine( 550.0, 125.0, 1350.0, 125.0 );

   glDisable( GL_LINE_STIPPLE );
   glFlush();
}

void reshape( int w, int h )
{
   glViewport( 0, 0, (GLsizei) w, (GLsizei) h );
   glMatrixMode ( GL_PROJECTION );
   glLoadIdentity();
   gluOrtho2D( 0.0, (GLdouble) w, 0.0, (GLdouble) h );
}

int main( int argc, char** argv )
{
   glutInit( &argc, argv );
   glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
   glutCreateWindow( argv[0] );
   init();
   glutDisplayFunc( display );
   glutReshapeFunc( reshape );
   glutMainLoop();
   return 0;
}

