#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>

void display(void)
{

  printf("void display(void)\n\n");

  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS);

  glEnd();

   //Desenhando o eixo x do plano cartesiano
   glBegin(GL_LINE_STRIP);
   glColor3f(0,1,0);
         glVertex2d(-1000,0);
         glVertex2d(1000,0);
   glEnd();

   //Desenhando o eixo y do plano cartesiano
   glBegin(GL_LINE_STRIP);
   glColor3f(0,0,1);
         glVertex2d(0,-1000);
         glVertex2d(0,1000);
   glEnd();

 glutSwapBuffers();
}

void reshape(int w, int h)
{

    printf("void reshape(int w, int h)\n\n");

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D (-1000, 1000, -1000, 1000); // Alterando os valores de proje��o voc� pode alterar o tamanho do seu volume de visualiza��o

}

int main(int argc, char **argv) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(200,200);
  glutInitWindowSize(512,512);
  glutCreateWindow("HelloCG");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  glutMainLoop();

  return 0;
}
