#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void draw_pixel(GLint cx,GLint cy)
{
glColor3f(1.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(cx,cy);
glEnd();
}

void plot_pixel(GLint h,GLint k,GLint x,GLint y)
{
draw_pixel(x+h,y+k);
draw_pixel(-x+h,y+k);
draw_pixel(x+h,-y+k);
draw_pixel(-x+h,-y+k);
draw_pixel(y+h,x+k);
draw_pixel(-y+h,x+k);
draw_pixel(y+h,-x+k);
draw_pixel(-y+h,-x+k);
}

void circle_draw(GLint h,GLint k,GLint r)
{
GLint d=1-r, x=0, y=r;
while (y>x)
{
plot_pixel(h,k,x,y);
if(d<0)    d+=2*x+3;
else
{
d+=2*(x-y)+5;
--y;
 } ++x;
}
plot_pixel(h,k,x,y);
}

void cylinder_draw()
{
GLint xc=100,yc=100,r=50;
GLint i,n=50;
for(i=0;i<n;i+=3)
circle_draw(xc,yc+i,r);
}

void parallelopiped(int x1,int x2,int y1,int y2,int y3,int y4)
{
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glBegin(GL_LINE_LOOP);
glVertex2f(x1,y1);
glVertex2f(x2,y3);
glVertex2f(x2,y4);
glVertex2f(x1,y2);
glEnd();
}


void parallelopiped_draw()
{
int x1=200,x2=300,y1=100,y2=175,y3=100,y4=175;
GLint i,n=40;
for(i=0;i<n;i+=2)
parallelopiped(x1+i,x2+i,y1+i,y2+i,y3+i,y4+i);
}

void init(void)
{
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,400.0,0.0,300.0);
}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glPointSize(2.0);
cylinder_draw();
parallelopiped_draw();
glFlush();
}

void main(int argc,char *argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("cylinder and parallelopiped");
glutDisplayFunc(display);
init();
glutMainLoop();
}
