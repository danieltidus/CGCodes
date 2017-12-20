/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 001

#include "LUtil.h"

bool initGL()
{
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    return true;
}

void update()
{

}

void render()
{
    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );
    //
    // glBegin(GL_POINTS);
    //   glVertex3f (0.25,0.25, 0.0);
    //   glVertex3f (0.75, 0.25, 0.0);
    //   glVertex3f (0.75, 0.75, 0.0);
    //   glVertex3f (0.25, 0.75, 0.0);
    // glEnd();
    //
    // glBegin(GL_LINE_LOOP);
    //   glVertex3f (0.25,0.25, 0.0);
    //   glVertex3f (0.75, 0.75, 0.0);
    //   glVertex3f (0.30, 0.45,0.0);
    //   glVertex3f (0.45, 0.12, 0.0);
    // glEnd();

    //
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(1.0, 0.0, 0.0);
      glVertex2f(-0.25, -0.25);
      glVertex2f(-0.75, -0.75);
      glVertex2f(-0.30, -0.45);
      glVertex2f(-0.45, -0.12);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
      glColor3f(1.0, 0.0, 1.0);
      glVertex2f(0.25, 0.25);
      glVertex2f(0.75, 0.75);
      glVertex2f(0.30, 0.45);
      glVertex2f(0.45, 0.12);
    glEnd();

    // //
    // glBegin(GL_POLYGON);
    //   glColor3f(1.0, 0.0, 0.0);
    //   glVertex2f (0.25,0.25);
    //   glColor3f(0.0, 1.0, 0.0);
    //   glVertex2f (0.75, 0.25);
    //   glColor3f(0.0, 0.0, 1.0);
    //   glVertex2f (0.75, 0.75);
    //   glColor3f(0.0, 0.0, 0.0);
    //   glVertex2f (0.25, 0.75);
    // glEnd();

    //Render quad
    // glBegin( GL_QUADS );
    //     glVertex2f( -0.5f, -0.5f );
    //     glVertex2f(  0.5f, -0.5f );
    //     glVertex2f(  0.5f,  0.5f );
    //     glVertex2f( -0.5f,  0.5f );
    // glEnd();

    //Update screen
    glutSwapBuffers();
}
