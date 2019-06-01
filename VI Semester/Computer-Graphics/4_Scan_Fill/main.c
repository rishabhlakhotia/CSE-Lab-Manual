#include<stdio.h>
#include<GL/glut.h>

static float x1=250.0,y1=150.0,x2=150.0,y2=250.0,x3=250.0,y3=350.0,x4=350.0,y4=250.0;

void edgeDetect(float x1,float y1,float x2,float y2,int *le, int *re)
{
	float mx, x, temp;
	int i;
	if((y2-y1)<0)
	{
		temp=y1;y1=y2;y2=temp;
		temp=x1;x1=x2;x2=temp;
	}
	if((y2-y1)!=0)
		mx=(x2-x1)/(y2-y1);
	else
		mx=x2-x1;
	x=x1;
	for(i=y1;i<=y2;i++)
	{
		if(x<(float)le[i])     le[i]=(int)x;
		if(x>(float)re[i])     re[i]=(int)x;
		x+=mx;
	}
}

void drawPixel(int x,int y)
{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}

void scanFill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
	int le[500],re[500];
	int i,y;
	for(i=0;i<500;i++)
	{
		le[i]=500;
		re[i]=0;
	}
	edgeDetect(x1,y1,x2,y2,le,re);
	edgeDetect(x2,y2,x3,y3,le,re);
	edgeDetect(x3,y3,x4,y4,le,re);
	edgeDetect(x4,y4,x1,y1,le,re);
	for(y=0;y<500;y++)
	{
		if(le[y]<=re[y])
		for(i=(int)le[y];i<(int)re[y];i++)
				drawPixel(i,y);
	}
}

void display(void)
{
    	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
glEnd();
scanFill(x1,y1,x2,y2,x3,y3,x4,y4);
	glFlush();
}

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
}

void main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("Scan Line fill");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}
