/*
 * GL04ModelTransform.cpp: Model Transform - Translation and Rotation
 * Transform primitives from their model spaces to world space.
 */
#include <stdio.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h


float angle = 0.0;
float tx,ty = 0.0f;
int sentido = 1;

/* Initialize OpenGL Graphics */
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque


   printf("----- Menu ----- \n");
   printf("Press A or a to rotate+ \n");
   printf("Press S or s  to rotate- \n");
   printf("Press W or w to translate right \n");
   printf("Press Q or q to translate left \n");
   printf("Press X or x to translate up \n");
   printf("Press Z or z to translate down \n");



}

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer
   glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
   glLoadIdentity();                // Reset the model-view matrix


   glTranslatef(tx, ty, 0.0f);      //Translate entire world


   //Local transformations
   glPushMatrix();
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   glTranslatef(0.0f, 0.8f, 0.0f); // Translate left and up
   glBegin(GL_QUADS);               // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f);  // Red
      glVertex2f(-0.3f, -0.3f);     // Define vertices in counter-clockwise (CCW) order
      glVertex2f( 0.3f, -0.3f);     //  so that the normal (front-face) is facing you
      glVertex2f( 0.3f,  0.3f);
      glVertex2f(-0.3f,  0.3f);
   glEnd();
   glPopMatrix();

   glPushMatrix();
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   glTranslatef(0.0f, -0.8f, 0.0f); // Translate right and down
   glBegin(GL_QUADS);               // Each set of 4 vertices form a quad
      glColor3f(0.0f, 1.0f, 0.0f); // Green
      glVertex2f(-0.3f, -0.3f);
      glVertex2f( 0.3f, -0.3f);
      glVertex2f( 0.3f,  0.3f);
      glVertex2f(-0.3f,  0.3f);
   glEnd();
   glPopMatrix();

   glPushMatrix();
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   glTranslatef(-0.8f, 0.0f, 0.0f); // Translate left and down
   glBegin(GL_QUADS);                // Each set of 4 vertices form a quad
      glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
      glVertex2f(-0.2f, -0.2f);
      glColor3f(1.0f, 1.0f, 1.0f); // White
      glVertex2f( 0.2f, -0.2f);
      glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
      glVertex2f( 0.2f,  0.2f);
      glColor3f(1.0f, 1.0f, 1.0f); // White
      glVertex2f(-0.2f,  0.2f);
   glEnd();
   glPopMatrix();

   glPushMatrix();
   glRotatef(angle, 0.0f, 0.0f, 1.0f); // Rotate 180 degree
   glTranslatef(0.8f, 0.0f, 0.0f);     // Translate right and down
      glBegin(GL_TRIANGLES);               // Each set of 3 vertices form a triangle
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(-0.3f, -0.2f);
      glColor3f(0.0f, 1.0f, 0.0f); // Green
      glVertex2f( 0.3f, -0.2f);
      glColor3f(0.0f, 0.0f, 1.0f); // Blue
      glVertex2f( 0.0f,  0.3f);
   glEnd();
   glPopMatrix();

   glPushMatrix();
   glRotatef(-angle, 0.0f, 0.0f, 1.0f); // Undo previous rotate
   //glTranslatef(-0.1f, 1.0f, 0.0f);      // Translate right and down
   glBegin(GL_POLYGON);                  // The vertices form one closed polygon
      glColor3f(1.0f, 1.0f, 0.0f); // Yellow
      glVertex2f(-0.1f, -0.2f);
      glVertex2f( 0.1f, -0.2f);
      glVertex2f( 0.2f,  0.0f);
      glVertex2f( 0.1f,  0.2f);
      glVertex2f(-0.1f,  0.2f);
      glVertex2f(-0.2f,  0.0f);
   glEnd();
   glPopMatrix();

   glFlush();   // Render now
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}


void keyboard(unsigned char key, int x, int y)
{

    switch (key) {
            case 'A':
            case 'a':
                     if(angle > 360.0f ) angle = 0.0f;
                     angle += 1.0f;
                     break;
            case 'S':
            case 's':
                     if(angle < 0.0f) angle = 360.0f;
                     angle -= 1.0f;
                     break;

            case 'Q':
            case 'q':
                     if(tx < -2.3f) tx = 2.3f;
                     tx -= 0.1f;
                     break;

            case 'W':
            case 'w':
                     if(tx > 2.3f) tx = -2.3f;
                     tx += 0.1f;
                     break;

            case 'Z':
            case 'z':
                     if(ty < -2.1f) ty = 2.1f;
                     ty -= 0.1f;
                     break;

            case 'X':
            case 'x':
                     if(ty > 2.1f) ty = -2.1f;
                     ty += 0.1f;
                     break;

            case 'I':
            case 'i':
                     sentido = -sentido;
                     break;

    }

    glutPostRedisplay();
}


void anima(int value){


     if(sentido == 1){
         if(angle > 360.0f ) angle = 0.0f;
         angle += 3.0f;
     }
     else{
         if(angle < 0.0f) angle = 360.0f;
         angle -= 1.0f;
     }


     glutPostRedisplay();
     glutTimerFunc(10,anima, 1);

}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitWindowSize(640, 480);   // Set the window's initial width & height - non-square
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("Model Transform");  // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutKeyboardFunc(keyboard); //Keyboard input callback

   glutTimerFunc(10, anima, 1);

   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
