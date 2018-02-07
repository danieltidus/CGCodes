/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 003

#include "LUtil.h"

//Viewport mode
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;
int proportion = 2;
GLfloat aspect=1;
GLfloat angle = 45;
char text[30];

float convertToRadian(float a){
  return a*3.14159/180.0;
}

bool initGL()
{
    //Set the viewport
    //glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );


    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    // Enable depth-buffering
    glEnable(GL_DEPTH_TEST);

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    return true;
}

void reshape(int w, int h){
  SCREEN_WIDTH = w;
  SCREEN_HEIGHT = h;

  if (h == 0) h = 1;                // To prevent divide by 0
    aspect = (GLfloat)w / (GLfloat)h;

  // glMatrixMode( GL_PROJECTION );
  // glLoadIdentity();
  // glOrtho(-aspect, aspect, -1, 1, -1.0f, 1.0f);
}

void update()
{

}

void drawScene(float br,float  bg,float  bb,float  obr,float  obg,float  obb){
  //Move to center of the screen
  glBegin( GL_QUADS );
      glColor3f( br, bg, bb );
      glVertex3f( -aspect, -aspect, 0.0f );
      glVertex3f(  aspect, -aspect,0.0f );
      glVertex3f(  aspect,  aspect,0.0f );
      glVertex3f( -aspect,  aspect,0.0f );
  glEnd();
  glColor3f(obr,obg,obb);
  glutWireTeapot(0.25);

}

void render()
{

    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    //First Viewport
    glViewport( 0.f, 0.f, SCREEN_WIDTH / proportion, SCREEN_HEIGHT / proportion );


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -aspect, aspect, -aspect, aspect);
    // Exibe a posi��o do mouse na janela
    glColor3f(0.0f,1.0f,0.0f);
    sprintf(text, "Orthogonal Projection");
    DrawText(text);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(-aspect, aspect, -1.0f, 1.0f, 1.0f, -1.0f);
    drawScene(0,0,0,1,1,1);




    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();




    //Second Viewport
    glViewport( SCREEN_WIDTH / proportion, 0.f, SCREEN_WIDTH / proportion, SCREEN_HEIGHT / proportion);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    float near = 0.1, far = 2;
    gluPerspective(angle,aspect,near,far);
    glTranslatef(0,0,-1);
    drawScene(1,1,1,0,0,0);



    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -aspect, aspect, -aspect, aspect);
    // Exibe a posi��o do mouse na janela
    glColor3f(1.0f,0.0f,0.0f);
    sprintf(text, "Symmetric Perspective Projection\n");
    DrawText(text);



    //Third Viewport
    glViewport( 0.f, SCREEN_HEIGHT / proportion, SCREEN_WIDTH / proportion, SCREEN_HEIGHT / proportion );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    float top = tan(convertToRadian(angle)/2)*near;
    float bottom = -top;
    glFrustum(aspect*bottom, aspect*top, bottom, top, near, far);
    glTranslatef(0,0,-1);
    drawScene(1,1,1,0,0,0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -aspect, aspect, -aspect, aspect);
    // Exibe a posi��o do mouse na janela
    glColor3f(1.0f,0.0f,0.0f);
    sprintf(text, "Symmetric Frustum\n");
    DrawText(text);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Fourth Viewport

    glViewport( SCREEN_WIDTH / proportion, SCREEN_HEIGHT / proportion, SCREEN_WIDTH / proportion, SCREEN_HEIGHT / proportion );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(aspect*bottom, aspect*top*2, bottom, top, near, far);
    glTranslatef(0,0,-1);
    drawScene(0,0,0,1,1,1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -aspect, aspect, -aspect, aspect);
    // Exibe a posi��o do mouse na janela
    glColor3f(0.0f,1.0f,0.0f);
    sprintf(text, "Assymmetric Perspective Frustum\n");
    DrawText(text);

    //Update screen
    glutSwapBuffers();
}

void handleKeys( unsigned char key, int x, int y )
{

}

void DrawText(char *string)
{
  	//glPushMatrix();
        // Posicao no universo onde o texto ser� colocado
        glRasterPos2f(-aspect,aspect - 0.2);
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24 ,*string++);

      //
      // glTranslatef(-aspect, aspect-(aspect*0.08), -0.5);
      // glScalef(100.10,100.10,100.0);
    	// while(*string)
      //   glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++);
	  //glPopMatrix();
}
