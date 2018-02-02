/*
 * 3DAndCurve.cpp: Model Transform - Translation and Rotation
 * Transform primitives from their model spaces to world space.
 */
#include <stdio.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

int WIRED_MODE = 1;
float angle = 0.0;
float tx,ty = 0.0f;
float sx = 1.0f,sy = 1.0f;
int sentido = 1;

/* Initialize OpenGL Graphics */
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque

   // Enable depth-buffering
   glEnable(GL_DEPTH_TEST);

}


void drawCube(){

  int draw_strategy = GL_QUADS;
  if(WIRED_MODE == 1)
    draw_strategy = GL_LINE_LOOP;

  glBegin(draw_strategy);
   // top
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex3f(-0.5f, 0.5f, 0.5f);
   glVertex3f(0.5f, 0.5f, 0.5f);
   glVertex3f(0.5f, 0.5f, -0.5f);
   glVertex3f(-0.5f, 0.5f, -0.5f);

   glEnd();

   glBegin(draw_strategy);
   // front
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex3f(0.5f, -0.5f, 0.5f);
   glVertex3f(0.5f, 0.5f, 0.5f);
   glVertex3f(-0.5f, 0.5f, 0.5f);
   glVertex3f(-0.5f, -0.5f, 0.5f);

   glEnd();

   glBegin(draw_strategy);
   // right
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex3f(0.5f, 0.5f, -0.5f);
   glVertex3f(0.5f, 0.5f, 0.5f);
   glVertex3f(0.5f, -0.5f, 0.5f);
   glVertex3f(0.5f, -0.5f, -0.5f);

   glEnd();

   glBegin(draw_strategy);
   // left
   glColor3f(0.0f, 0.0f, 0.5f);
   glVertex3f(-0.5f, -0.5f, 0.5f);
   glVertex3f(-0.5f, 0.5f, 0.5f);
   glVertex3f(-0.5f, 0.5f, -0.5f);
   glVertex3f(-0.5f, -0.5f, -0.5f);

   glEnd();

   glBegin(draw_strategy);
   // bottom
   glColor3f(0.5f, 0.0f, 0.0f);
   glVertex3f(0.5f, -0.5f, 0.5f);
   glVertex3f(-0.5f, -0.5f, 0.5f);
   glVertex3f(-0.5f, -0.5f, -0.5f);
   glVertex3f(0.5f, -0.5f, -0.5f);

   glEnd();

   glBegin(draw_strategy);
   // back
   glColor3f(0.0f, 0.5f, 0.0f);
   glVertex3f(0.5f, 0.5f, -0.5f);
   glVertex3f(0.5f, -0.5f, -0.5f);
   glVertex3f(-0.5f, -0.5f, -0.5f);
   glVertex3f(-0.5f, 0.5f, -0.5f);
   glEnd();

}

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Clear the color buffer

   glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
   glLoadIdentity();                // Reset the model-view matrix


   glScalef(sx, sy, 1.0f);
   glTranslatef(tx, ty, 0.0f);      //Translate entire world

   glPushMatrix();
   //glLoadIdentity();
   glTranslatef(0.0f, 0.6f, 0.0f); // Translate left and up
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   glColor3f(1.0f, 0.0f, 0.0f);
   if(WIRED_MODE == 1)
    glutWireTeapot(0.25);
   else
    glutSolidTeapot(0.25);

   glPopMatrix();

   glPushMatrix();
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   glTranslatef(0.0f, -0.6f, 0.0f); // Translate left and up
   glScalef(0.5, 0.50, 0.50);
   glRotatef(45,1.0f, 1.0f, 1.0f);
   drawCube();
   glPopMatrix();

   glPushMatrix();
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   glTranslatef(0.6f, 0.0f, 0.0f); // Translate left and up
   glColor3f(0.0f, 0.0f, 1.0f);
   if(WIRED_MODE == 1)
    glutWireTorus(0.07,0.28,20, 20);
   else
    glutSolidTorus( 0.07,0.28,20, 20);
   glPopMatrix();

   glPushMatrix();
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   glTranslatef(-0.6f, 0.0f, 0.0f); // Translate left and up
   glColor3f(1.0f, 1.0f, 0.0f);

   if(WIRED_MODE == 1)
       glutWireSphere(0.25,20,20);
   else
       glutSolidSphere(0.25,20,20);
   glPopMatrix();

   glutSwapBuffers();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer

  printf("(width: %d , height: %d)\n", width, height);
   // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
      GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   //Initialize Modelview Matrix
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();


   //Initialize Projection Matrix
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   glOrtho(-aspect, aspect, -1, 1, -1.0f, 1.0f);

}


void keyboard(unsigned char key, int x, int y)
{

    switch (key) {
            case 'A':
            case 'a':
                     angle += 1.0f;
                     if(angle > 360.0f ) angle = 0.0f;
                     break;
            case 'S':
            case 's':
                     angle -= 1.0f;
                     if(angle < 0.0f) angle = 360.0f;
                     break;

            case 'Q':
            case 'q':
                     tx -= 0.1f;
                     if(tx < -2.3f) tx = 2.3f;
                     break;

            case 'W':
            case 'w':
                     tx += 0.1f;
                     if(tx > 2.3f) tx = -2.3f;
                     break;

            case 'Z':
            case 'z':
                     ty -= 0.1f;
                     if(ty < -2.1f) ty = 2.1f;
                     break;

            case 'X':
            case 'x':
                     ty += 0.1f;
                     if(ty > 2.1f) ty = -2.1f;
                     break;

             case 'E':
             case 'e':
                      sx -= 0.1f;
                      if(sx < 0.0f) sx = 0.0f;
                      break;

             case 'R':
             case 'r':
                     sx += 0.1f;
                     if(sx > 10.0f) sx = 10.0f;
                     break;

           case 'D':
           case 'd':
                    sy -= 0.1f;
                    if(sy < 0.0f) sy = 0.0f;
                    break;

           case 'F':
           case 'f':
                   sy += 0.1f;
                   if(sy > 10.0f) sy = 10.0f;
                   break;

           case 'C':
           case 'c':
                   sy -= 0.1f;
                   if(sy < 0.0f) sy = 0.0f;
                   sx -= 0.1f;
                   if(sx < 0.0f) sx = 0.0f;
                    break;

           case 'V':
           case 'v':
                   sy += 0.1f;
                   if(sy > 10.0f) sy = 10.0f;
                   sx += 0.1f;
                   if(sx > 10.0f) sx = 10.0f;
                   break;


          case 'T':
          case 't':
                  if(WIRED_MODE)
                    WIRED_MODE = 0;
                  else
                    WIRED_MODE = 1;

                  break;

    }

    glutPostRedisplay();
}



/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(640, 480);   // Set the window's initial width & height - non-square
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("Model Transform");  // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutKeyboardFunc(keyboard); //Keyboard input callback

   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
