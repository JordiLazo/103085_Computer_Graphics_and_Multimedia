#include<GL/glut.h>
#include<iostream>
#include"draw.h"

#define COLUMNS 22
#define ROWS 21
#define WIDTH 1200
#define HEIGHT 700

void display();

GenerateMap *map;

int main(int argc, char *argv[]) {
    GenerateMap newMap(COLUMNS,ROWS);
    newMap.printTable();
    map = &newMap;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);

    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Pacman Work Package 1");

    glutDisplayFunc(display);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,WIDTH-1,HEIGHT-1,0);

    glutMainLoop();
    return 0;
}

void display(){
    glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawVector(WIDTH,HEIGHT,*map);
    glutSwapBuffers();
}