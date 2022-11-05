#include<GL/glut.h>
#include<iostream>
#include"map.h"
#include"characters.h"


//-----MAP SIZE-----//
#define COLUMNS 25
#define ROWS 25

//-----OPEN GL-----//
void display();

//-----WINDOW SIZE-----//
#define WIDTH 1400
#define HEIGHT 700

//-----GLOBAL FUNCTIONS-----//


//-----GLOBAL VARIABLES-----//
int pixelSize; //pixels size of each position of the map
Map map;
Player player;

int main(int argc, char *argv[]) {
    map.generateMap(COLUMNS,ROWS);
    map.printMap();
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    pixelSize = min(WIDTH/COLUMNS, HEIGHT/ROWS);
    printf("Pixels size:%d\n",pixelSize);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Pacman Work Package 2");
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,WIDTH-1,HEIGHT-1,0);
    glutMainLoop();
    return 0;
}

void display(){
    glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    map.drawMap(pixelSize);
    map.drawFood(pixelSize);
    player.createPlayer(pixelSize, pixelSize-2, map.startPosition());
    glutSwapBuffers();
}