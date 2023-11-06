#include <GL/gl.h>
#include <GL/glut.h>

void display( void )
{
   static GLint vertices[] = {
      25, 25,
      100, 325,
      175, 25,
      175, 325,
      250, 25,
      325, 325};

   static GLfloat colors[] = {
      1.0, 0.2, 0.2,
      0.2, 0.2, 1.0,
      0.8, 1.0, 0.2,
      0.75, 0.75, 0.75,
      0.35, 0.35, 0.35,
      0.5, 0.5, 0.5};

   glClearColor( 1.0, 1.0, 1.0, 0.0 );
   glShadeModel( GL_FLAT );
   glClear( GL_COLOR_BUFFER_BIT );
   glLineWidth( 10 );

   glEnableClientState( GL_COLOR_ARRAY );
   glEnableClientState( GL_VERTEX_ARRAY );

   glColorPointer( 3, GL_FLOAT, 0, colors );
   glVertexPointer( 2, GL_INT, 0, vertices );


/* glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); */
   glBegin( GL_TRIANGLES );

   glArrayElement( 2 );
   glArrayElement( 3 );
   glArrayElement( 5 );

   glArrayElement( 0 );
   glArrayElement( 1 );
   glArrayElement( 5 );

   glEnd();
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
   if( key == 27 ) exit( 0 ); /* 27 is the excape key */
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

