#include<GL/glut.h>
#include<iostream>
#include"map.h"
#include"player.h"
#include"food.h"

//-----------------------------------MAP SIZE-----------------------------------//
#define COLUMNS 20
#define ROWS 20

//-----------------------------------OPEN GL-----------------------------------//
void display();
void keyboard(int key, int x, int y);
void idle();

//-----------------------------------WINDOW SIZE-----------------------------------//
#define WIDTH 1400
#define HEIGHT 700

//-----------------------------------GLOBAL FUNCTIONS-----------------------------------//
void foodCollision();
bool checkFoodCollision(Position obj1, Position obj2);

//-----------------------------------GLOBAL VARIBALES-----------------------------------//
int pixelSize; //pixels size of each position of the map
Map map;
Player player;
Food food;
long lastTime = 0;
//-----------------------------------MAIN-----------------------------------//
int main(int argc, char *argv[]) {
//-----------------------------------SET UP-----------------------------------//
    map.generateMap(COLUMNS,ROWS);
    map.printMap();
    pixelSize = min(WIDTH/COLUMNS, HEIGHT/ROWS);
    printf("Pixels size:%d\n",pixelSize);
    Position init = player.startPosition(map);
    player.createPlayer(pixelSize, pixelSize-15, init);
    food.insertFood(pixelSize,map);
//-----------------------------------OPEN GL-----------------------------------//
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Pacman Work Package 2");
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutIdleFunc(idle);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,WIDTH-1,HEIGHT-1,0);
    glutMainLoop();
    return 0;
}

void display(){
    glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    map.drawMap(pixelSize);
    //map.drawFood(pixelSize);
    food.drawFood(pixelSize);
    player.drawPlayer();
    glutSwapBuffers();
}

void keyboard(int key, int x, int y){
    player.handleKeyboard(key);
    glutPostRedisplay();
}

void idle(){
    long currentTime;
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    player.createMove(currentTime-lastTime);
    player.foodCollision(&food.foodList);
    lastTime = currentTime;
    glutPostRedisplay();
}