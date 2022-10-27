#include<GL/glut.h>
#include<iostream>
#include"generateMap.h"

#define COLUMNS 53
#define ROWS 52
#define WIDTH 1000
#define HEIGHT 700

void display();

GenerateMap *map;

int main(int argc, char *argv[]) {
    GenerateMap arrayMap(COLUMNS,ROWS);
    arrayMap.printTable();
    map = &arrayMap;
    
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

    for(int i = 0; i < map->rows; i++){
        for(int j = 0; j < map->columns; j++){
            if(map->array[i][j] == PATH){
                glColor3f(0.8,0.8,0.8);
                glColor3f(0.8,0.8,0.8);
                glBegin(GL_QUADS);
                glVertex2i(j*WIDTH/map->columns,i*HEIGHT/map->rows);
                glVertex2i((j+1)*WIDTH/map->columns,i*HEIGHT/map->rows); 
                glVertex2i((j+1)*WIDTH/map->columns,(i+1)*HEIGHT/map->rows); 
                glVertex2i(j*WIDTH/map->columns,(i+1)*HEIGHT/map->rows); 
                glEnd();
            }
        }
  	}
    glutSwapBuffers();
}