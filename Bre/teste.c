//
#include<iostream>
#include<graphics.h>
using namespace std;

const int CENTERX = 260;
const int CENTERY = 260;

void bresenham1(int x1, int y1, int x2, int y2){
        int slope;
        int dx, dy, incE, incNE, d, x, y;
        // Onde inverte a linha x1 > x2
        if (x1 > x2){
            bresenham1(x2, y2, x1, y1);
             return;
        }
        dx = x2 - x1;
        dy = y2 - y1;

        if (dy < 0){
            slope = -1;
            dy = -dy;
        }
        else{
           slope = 1;
        }
        // Constante de Bresenham
        incE = 2 * dy;
        incNE = 2 * dy - 2 * dx;
        d = 2 * dy - dx;
        y = y1;
        for (x = x1; x <= x2; x++){
            putpixel(x+CENTERX, y+CENTERY, 100);
            if (d <= 0){
              d += incE;
            }
            else{
              d += incNE;
              y += slope;
            }
        }
  }



int main()
{
  int gd=DETECT,gm,x,y;
  initgraph(&gd,&gm,NULL);
  bresenham1(-10,-10,20,25);
  // for(int i = 0; i< 1000; i++)
  //    putpixel(i, i, 10);
  getch();
  closegraph();
  return 0;
}
