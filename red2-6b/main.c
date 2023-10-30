/*
 * main.c
 * made by Josh Riff
 * 10/29/2023
 *
 * creates a fly image and moves it across the screen using the aswd controls
 * press the escape key to exit
 * if in linux, after you press escape if you are running it in vim, press enter
*/
#include <GL/gl.h>
#include <GL/glut.h>

int moveRight = 0;
int moveUp    = 0;

void display( void )
{
   GLubyte fly[] = {
      0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff,
      0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00,
      0x03, 0x80, 0x01, 0xc0,
      0x06, 0xc0, 0x03, 0x60, 
      0x04, 0x60, 0x06, 0x20,
      0x04, 0x30, 0x0c, 0x20,
      0x04, 0x18, 0x18, 0x20,
      0x04, 0x0c, 0x30, 0x20,
      0x04, 0x06, 0x60, 0x20,
      0x44, 0x03, 0xc0, 0x22,
      0x44, 0x01, 0x80, 0x22,
      0x44, 0x01, 0x80, 0x22,
      0x44, 0x01, 0x80, 0x22,
      0x44, 0x01, 0x80, 0x22,
      0x44, 0x01, 0x80, 0x22,
      0x44, 0x01, 0x80, 0x22,
      0x66, 0x01, 0x80, 0x66,
      0x33, 0x01, 0x80, 0xcc,
      0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00,
      0xff, 0xff, 0xff, 0xff,
      0x00, 0x00, 0x00, 0x00,
      0xff, 0xff, 0xff, 0xff,
      0x00, 0x00, 0x00, 0x00};
      

   glClear( GL_COLOR_BUFFER_BIT );
   glColor3f( 1.0, 0.0, 0.0 );

   /* draw one solid, ontrippled rectangle,
    * then two stippled rectangles
    */
   glEnable( GL_POLYGON_STIPPLE );
   glPolygonStipple( fly );
   glRectf( moveRight, moveUp, moveRight+32, moveUp+32 );
   glPolygonStipple( fly );
   glRectf( 96.0, 96.0, 128.0, 128.0 );
   glDisable( GL_POLYGON_STIPPLE );

   glFlush();
}

void init( void )
{
   glClearColor( 0.0, 0.0, 0.0, 0.0 );
   glShadeModel( GL_FLAT );
}

void reshape( int w, int h )
{
   glViewport( 0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   gluOrtho2D( 0.0, (GLdouble) w, 0.0, (GLdouble) h );
}

void keyboard (unsigned char key, int x, int y )
{
   /*
    * use the aswd controls to move the fly
    *
    * w: move up
    * a: move left
    * s: move down
    * d: move right
   */ 
   switch (key)
   {
      case 'w':
         moveUp++;
         break;
      case 'a':
         moveRight--;
         break;
      case 's':
         moveUp--;
         break;
      case 'd':
         moveRight++;
         break;
      case (char)27:
         exit(0);
      default:
         break;
   }
   display();
}


int main( int argc, char** argv )
{
   glutInit( &argc, argv );
   glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
   glutInitWindowSize( 350, 150 );
   glutCreateWindow( argv[0] );
   init();
   glutDisplayFunc( display );
   glutReshapeFunc( reshape );
   glutKeyboardFunc( keyboard );
   glutMainLoop();
   return 0;
}

