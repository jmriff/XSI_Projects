#include <GL/gl.h>
#include <GL/glut.h>

void display( void )
{
   glClearColor( 0.0, 0.0, 0.0, 0.0 );
   glShadeModel( GL_FLAT );
   glClear( GL_COLOR_BUFFER_BIT );
   glColor3f( 1.0, 0.0, 0.0 );

/*     Brian's code goes here    */











   glFlush();
}

void reshape( int w, int h )
{
   glViewport( 0, 0, (GLsizei) w, (GLsizei) h );
   glLoadIdentity();
   gluOrtho2D( 0.0, (GLdouble) w, 0.0, (GLdouble) h );
}

void keyboard( unsigned char key, int x, int y )
{
   if( key == 27 ) exit( 0 );  /* 27 is the escape key */
}

int main( int argc, char** argv )
{
   glutInit( &argc, argv );
   glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
   glutInitWindowSize( 350, 150 );
   glutCreateWindow( argv[0] );
   glutDisplayFunc( display );
   glutReshapeFunc( reshape );
   glutKeyboardFunc( keyboard );
   glutMainLoop();
   return 0;
}

