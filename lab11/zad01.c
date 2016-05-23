#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <GL/glut.h>

void print()
{
  glClearColor(0.0, 0.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  int n;
  printf("Podaj ilosc katow:\n");
  scanf("%d", &n);

  glBegin(GL_LINE_LOOP);
  double PI=3.14, fi, x, y;
  fi = 2*PI/n;
  for(int i=0; i<n; i++)
  {
    x=cos(i*fi);
    y=sin(i*fi);
    glVertex3d(x, y, 0);
  }
  glEnd();
  glFlush();
  glutSwapBuffers();
}

void changesize(int width, int height)
{
    print();
}



int main(int arg_num, char * arg[])
{
    glutInit(&arg_num, arg);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 500,500 );
    glutCreateWindow("Draw Regular Polygons");
    glutDisplayFunc( print );
    glutReshapeFunc( changesize );
    glutMainLoop();
}
