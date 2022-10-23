#include<GL/glut.h>
#include<iostream>
#include"map.h"

#define COLUMNS 11
#define ROWS 11


#define WIDTH 600
#define HEIGHT 600

void display();



int main(int argc, char *argv[]) {
    Table table(COLUMNS,ROWS);
    table.printTable();

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

    glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            // glColor3f(0.8,0.8,0.8);
            // glBegin(GL_QUADS);
            // glVertex2i(x,y);
            // glVertex2i(x,y+height);
            // glVertex2i(x+width, y+height);
            // glVertex2i(x+width, y);
            // glEnd();
        }
  	}

    glutSwapBuffers();

}