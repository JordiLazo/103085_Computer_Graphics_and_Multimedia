#include<GL/glut.h>
#include<iostream>
#include"map.h"




#define WIDTH 600
#define HEIGHT 600

void display();

Table *table;

int main(int argc, char *argv[]) {
    int columns = 12;
    int rows = 12;
    Table mainTable(columns,rows);
    mainTable.printTable();
    table = &mainTable;
    
    // GLUT init
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);

    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Pacman Task 1");

    glutDisplayFunc(display);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,WIDTH-1,HEIGHT-1,0);

    glutMainLoop();
    return 0;
}

void display(){
    int i, j;
    int rows = table->ROWS;
    int columns = table->COLUMNS;

    glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            if(table->array[i][j] == PATH){
                glColor3f(0.8,0.8,0.8);
                glColor3f(0.8,0.8,0.8);
                glBegin(GL_QUADS);
                glVertex2i(j*WIDTH/columns,i*HEIGHT/rows);
                glVertex2i((j+1)*WIDTH/columns,i*HEIGHT/rows); 
                glVertex2i((j+1)*WIDTH/columns,(i+1)*HEIGHT/rows); 
                glVertex2i(j*WIDTH/columns,(i+1)*HEIGHT/rows); 
                glEnd();

            }

        }
  	}

    glutSwapBuffers();

}