#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <stack>
#include <GL/glut.h>
#include "generate_map.h"



using namespace std;

Cell **globalMap;
Cell **globalMapBig;
int *globalHeight;
int *globalWeight;
//-----------------------------------------------
void display(); 


int main (int argc, char *argv[]) {
	srand (time(NULL));
	//char* HEIGHT_CHAR;
	//char* WEIGHT_CHAR;
	//HEIGHT_CHAR=argv[1];
	//WEIGHT_CHAR=argv[2];
	//int HEIGHT= atoi(HEIGHT_CHAR);
	//int WEIGHT = atoi(WEIGHT_CHAR);
	int HEIGHT= 10;
	int WEIGHT = 10;
	
	printf("%d x %d\n",HEIGHT,WEIGHT);
	globalHeight=&HEIGHT;
	globalWeight=&WEIGHT;
	glutInit(&argc, argv);
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  	glutInitWindowPosition(50, 50);
  	glutInitWindowSize(500, 500);
  	glutCreateWindow("PacMan");

	globalMap=dfs_generation(HEIGHT, WEIGHT);
	


	glutDisplayFunc(display);	  
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,WEIGHT-1,HEIGHT-1,0);
	
	
  	glutMainLoop();
  
  	return 0;
}

//-----------------------------------------------
//-----------------------------------------------
void display()
{

	int WIDTH=*globalWeight;
	int HEIGHT=*globalHeight;
	int COLUMNS=*globalWeight-1;
	int ROWS=*globalHeight-1;
	int i,j;

	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	for(i=0;i<HEIGHT;i++)
		for(j=0;j<WIDTH;j++)
		if( globalMap[i][j].value==1) 
		{
		glColor3f(0.8,0.8,0.8);
		glBegin(GL_QUADS);

		glVertex2i(j*(WIDTH/COLUMNS),i*(HEIGHT/ROWS)); 
		glVertex2i((j+1)*(WIDTH/COLUMNS),i*(HEIGHT/ROWS)); 
		glVertex2i((j+1)*(WIDTH/COLUMNS),(i+1)*(HEIGHT/ROWS)); 
		glVertex2i(j*(WIDTH/COLUMNS),(i+1)*(HEIGHT/ROWS)); 

		glEnd();
		}

	glutSwapBuffers();

}