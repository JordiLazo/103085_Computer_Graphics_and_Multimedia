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
    //map.insertFood(pixelSize);
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
    //foodCollision();
    food.foodCollision(player);
    lastTime = currentTime;
    glutPostRedisplay();
}
/*
void foodCollision() {
    std::list<Food>::iterator food;
    for (food = map.foodList.begin(); food != map.foodList.end(); ++food){
        Position obj1 = Position(player.x, player.y);
        Position obj2 = Position(food->x, food->y);
        if(checkFoodCollision(obj1, obj2)) {
            food = map.foodList.erase(food);
        }
    }
}
bool checkFoodCollision(Position obj1, Position obj2) {
    float dist = pixelSize/1.5;
    float dx = abs(obj1.x - obj2.x);
    float dy = abs(obj1.y - obj2.y);
    return dx  +  dy <= dist;
}
*/