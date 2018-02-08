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
float z = -3;
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
}

void update()
{
    if(angle > 360)
      angle = 0;
    angle += 1;
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
  glutSolidTeapot(0.25);

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
    gluPerspective(50.0, 1.0, 3.0, 7.0);
    glTranslatef(0,0,-3);
    gluLookAt(cos(convertToRadian(angle)), 2.0, sin(convertToRadian(angle)), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(1,1,1);
    glutWireTeapot(1);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -aspect, aspect, -aspect, aspect);
    // Exibe a posi��o do mouse na janela
    glColor3f(1.0f,1.0f,1.0f);
    sprintf(text, "Fixed Y Axis");
    DrawText(text);



    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Second Viewport
    glViewport( SCREEN_WIDTH / proportion, 0.f, SCREEN_WIDTH / proportion, SCREEN_HEIGHT / proportion);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, 1.0, 3.0, 7.0);
    glTranslatef(0,0,-4);
    gluLookAt(2.0, cos(convertToRadian(angle)), sin(convertToRadian(angle)), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(1,1,1);
    glutWireTeapot(1);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -aspect, aspect, -aspect, aspect);
    // Exibe a posi��o do mouse na janela
    glColor3f(1.0f,1.0f,1.0f);
    sprintf(text, "Fixed X Axis");
    DrawText(text);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    //Third Viewport
    glViewport( 0.f, SCREEN_HEIGHT / proportion, SCREEN_WIDTH / proportion, SCREEN_HEIGHT / proportion );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, 1.0, 3.0, 7.0);
    glTranslatef(0,0,-4);
    gluLookAt(cos(convertToRadian(angle)),  sin(convertToRadian(angle)), 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(1,1,1);
    glutWireTeapot(1);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -aspect, aspect, -aspect, aspect);
    // Exibe a posi��o do mouse na janela
    glColor3f(1.0f,1.0f,1.0f);
    sprintf(text, "Fixed Z Axis");
    DrawText(text);

    //Fourth Viewport

    glViewport( SCREEN_WIDTH / proportion, SCREEN_HEIGHT / proportion, SCREEN_WIDTH / proportion, SCREEN_HEIGHT / proportion );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, 1.0, 3.0, 30.0);
    glTranslatef(0,0,-5);
    gluLookAt(2.5,  1.5,  z, 0.0, z, 0.0, 0.0, 1.0, 0.0);
    glColor3f(1,1,1);
    glutWireTorus(0.05,0.2,20,20);




    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -aspect, aspect, -aspect, aspect);
    // Exibe a posi��o do mouse na janela
    glColor3f(1.0f,1.0f,1.0f);
    sprintf(text, "Fixed Camera");
    DrawText(text);


    //Update screen
    glutSwapBuffers();
}

void handleKeys( unsigned char key, int x, int y )
{
  switch (key) {
    case 'A'/* value */:
    case 'a':
      z += 0.1;
      break;
    case 'S'/* value */:
    case 's':
      z -= 0.1;
      break;

  }
      printf("Valor de z: %f\n", z);

}
void DrawText(char *string)
{
  	glPushMatrix();
        // Posicao no universo onde o texto ser� colocado
        glRasterPos2f(-aspect,aspect-(aspect*0.16));
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24 ,*string++);

      //
      // glTranslatef(-aspect, aspect-(aspect*0.08), -0.5);
      // glScalef(100.10,100.10,100.0);
    	// while(*string)
      //   glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++);
	  glPopMatrix();
}
