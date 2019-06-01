#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void wall(double thickness)
{
  glPushMatrix();
  glTranslated(0.5,0.5*thickness,0.5);
  glScaled(1.0,thickness,1.0);
  glutSolidCube(1.0);
  glPopMatrix();
}

void tableleg(double thick,double len)
{
  glPushMatrix();
  glTranslated(0,len/2,0);
  glScaled(thick,len,thick);
  glutSolidCube(1.0);
  glPopMatrix();
}

void table(double topw,double topt,double legt,double legl)
{
  glPushMatrix();
  glTranslated(0,legl,0);
  glScaled(topw,topt,topw);
  glutSolidCube(1.0);
  glPopMatrix();
  double dist=0.95*topw/2.0-legt/2.0;
  glPushMatrix();
  glTranslated(dist,0,dist);
  tableleg(legt,legl);
  glTranslated(0,0,-2*dist);
  tableleg(legt,legl);
  glTranslated(-2*dist,0,2*dist);
  tableleg(legt,legl);
  glTranslated(0,0,-2*dist);
  tableleg(legt,legl);
  glPopMatrix();
}

void displaysolid(void)
{
  GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
  GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
  GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
  GLfloat mat_shininess[]={50.0f};

  glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
  glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
  glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

  GLfloat lightint[]={0.7f,0.7f,0.7f,1.0f};
  GLfloat lightpos[]={2.0f,6.0f,3.0f,0.0f};

  glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
  glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  double winht=1.0;
  glOrtho(-winht*64/48.0,winht*64/48.0,-winht,winht,0.1,100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(2.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  glRotated(90.0,0.0,0.0,1.0);
  wall(0.02);
  glPopMatrix();

  wall(0.02);
  glPushMatrix();
  glRotated(-90.0,1.0,0.0,0.0);
  wall(0.02);
  glPopMatrix();

  glPushMatrix();
  glTranslated(0.4,0,0.4);
  table(0.6,0.02,0.02,0.3);
  glPopMatrix();

  glPushMatrix();
  glTranslated(0.6,0.38,0.5);
  glRotated(30,0,1,0);
  glutSolidTeapot(0.08);
  glPopMatrix();
  glFlush();
}

void main(int argc,char**argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("teapot");
glutDisplayFunc(displaysolid);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
glEnable(GL_NORMALIZE);
glClearColor(0.1,0.1,0.1,0.0);
glViewport(0,0,640,480);
glutMainLoop();
}
