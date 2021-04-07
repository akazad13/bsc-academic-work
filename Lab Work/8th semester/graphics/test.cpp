#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include<GL/glut.h>
#include<GL/gl.h>
#include<windows.h>
#endif

#include<stdio.h>
#include<math.h>

void traingle()
{
    glClear(GL_COLOR_BUFFER_BIT); // use backgroundcolor glClearColor()

    glLoadIdentity(); //stop rotating and show particular rotation
    glRotatef( 45, 0.0, 1.0, 0.0);

    glBegin( GL_TRIANGLES );
        // set color for all upcoming draw calls
        glColor3f(0.0, 1.0, 0.0);  // RGB color

        // Three point x,y,z

        glVertex3f(-0.5, -0.5, 0.0); // Create a geometric point
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f( 0.5, -0.5, 0.0);

        glColor3f(0.0, 0.0, 1.0);
        glVertex3f( 0.0,  0.5, 0.0);

    glEnd();

    glutSwapBuffers(); // double buffer
}


void flag()
{
    glClear(GL_COLOR_BUFFER_BIT); // use backgroundcolor glClearColor()

    glColor3f(0.0, 1.0, 0.0);  // RGB color

    glBegin(GL_POLYGON);
        glVertex3f (50, 150, 0.0);
        glVertex3f (350, 150, 0.0);
        glVertex3f (350, 300, 0.0);
        glVertex3f (50, 300, 0.0);
    glEnd();


    glColor3f(1.0, 0.0, 0.0);

    float alpha;

    glBegin(GL_POLYGON);
        for(int i=0;i<360;i++)
        {
            alpha = (i*3.1415)/180.0;
            glVertex3f(200+60*cos(alpha), 225+60*sin(alpha), 0.0);
        }
    glEnd();

   glutSwapBuffers(); // double buffer
}

void points()
{
    glClear(GL_COLOR_BUFFER_BIT); // use backgroundcolor glClearColor()

    glColor3f(0.0, 0.0, 1.0);

    glBegin( GL_POINTS );
        glVertex2i( 10, 10 );		//draw a point
        glVertex2i( 100, 150 );		//draw a point
        glVertex2i( 200, 180 );
	glEnd();

    glutSwapBuffers(); // double buffer
}

void lines()
{
    glClear(GL_COLOR_BUFFER_BIT); // use backgroundcolor glClearColor()

    glColor3f(0.0, 1.0, 0.0);  // RGB color

    glColor3f(1.0, 0.0, 0.0);

	 glBegin( GL_LINES );
        glVertex2i( 100, 80 );		//draw a point
        glVertex2i( 300, 80 );		//draw a point
	glEnd();

   glutSwapBuffers(); // double buffer


}

void circle()
{
    glClear(GL_COLOR_BUFFER_BIT); // use backgroundcolor glClearColor()

    glColor3f(1.0, 0.0, 0.0);

    float alpha, r = 80, h=200, k=240;

    glBegin(GL_POLYGON);
        for(int i=0;i<360;i++)
        {
            alpha = (i*3.1415)/180.0;
            glVertex3f(h+r*cos(alpha), k+r*sin(alpha), 0.0);
        }
    glEnd();


    // Bresenham's algorithm
    glColor3f(0.0, 1.0, 0.0);

    r = 80;
    float x =0, y = r, d = 3-2*r;
    h = 100;
    k = 100;

    glBegin(GL_POLYGON);
        while(x<=y)
        {
            glVertex3f(x+h,y+k, 0.0);
            glVertex3f(y+h,x+k, 0.0);
            glVertex3f(-y+h,x+k, 0.0);
            glVertex3f(-x+h,y+k, 0.0);
            glVertex3f(-x+h,-y+k, 0.0);
            glVertex3f(-y+h,-x+k, 0.0);
            glVertex3f(y+h,-x+k, 0.0);
            glVertex3f(x+h,-y+k, 0.0);

            if(d<0)
                d = d+4*x+6;
            else
            {
                d = d+4*(x-y)+10;
                y--;
            }
            x++;
        }
    glEnd();

    // Bresenham's algorithm

   glutSwapBuffers(); // double buffer
}

void reshape( int w, int h)
{
    glViewport( 0, 0, w, h); //

}

void initOpenGL()
{
    // color channel : RGB alpha
    glClearColor( 1.0 , 1.0 , 1.0 , 1.0 );

}

void init( void )
{
  glClearColor( 1.0, 1.0, 1.0, 0.0 );	//get white background color
  //glColor3f( 0.0f, 0.0f, 0.0f );	//set drawing color
  glPointSize( 4.0 );			//a dot is 4x4
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();			//replace current matrix with identity matrix
  gluOrtho2D( 0.0, 400.0, 0.0, 400.0 );
}

int main(int argc, char **argv)
{
    // start up freeglut
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   // glutInitDisplayMode( GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize( 500, 500);
    glutInitWindowPosition( 100, 100);
    glutCreateWindow( "First openGL App" );

    //initOpenGL();
    init();

    glutDisplayFunc( circle );
    glutIdleFunc( circle );
    glutReshapeFunc( reshape );
    glutMainLoop();


    return 0;
}
