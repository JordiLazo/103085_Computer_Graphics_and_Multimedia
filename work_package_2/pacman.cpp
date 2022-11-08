#include<GL/glut.h>
#include<iostream>
#include"map.h"
#include"player.h"
#include"food.h"
#include"enemy.h"

//-----------------------------------MAP SIZE-----------------------------------//
#define COLUMNS 20
#define ROWS 20
//-----------------------------------WINDOW SIZE-----------------------------------//
#define WIDTH 1400
#define HEIGHT 700
//-----------------------------------OPEN GL-----------------------------------//
void display();
void keyboard(int key, int x, int y);
void idle();
//-----------------------------------GLOBAL FUNCTIONS-----------------------------------//
void insertEnemies();
void createMoveEnemies();
//-----------------------------------GLOBAL VARIBALES-----------------------------------//
Map map;
Player player;
Food food;
Enemy enemy;
list<Enemy> listOfEnemies;
int pixelSize; //pixels size of each position of the map
int numberOfEnemies;
long lastTime = 0;
long currentTime;
//-----------------------------------MAIN-----------------------------------//
int main(int argc, char *argv[]) {
//-----------------------------------SET UP GAME-----------------------------------//
    pixelSize = min(WIDTH/COLUMNS, HEIGHT/ROWS);
    numberOfEnemies = max(COLUMNS,ROWS)/5;
    printf("ENEMIES:%d\n", numberOfEnemies);
    map.insertMap(COLUMNS,ROWS);
    food.insertFood(pixelSize,map);
    insertEnemies();
    map.printMap();
    printf("Pixels size:%d\n",pixelSize);
    Position init = player.startPosition(map);
    player.createPlayer(pixelSize, pixelSize-14, init);
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
    food.drawFood(pixelSize);
    enemy.drawEnemies(listOfEnemies);
    player.drawPlayer();
    glutSwapBuffers();
}

void keyboard(int key, int x, int y){
    player.handleKeyboard(key);
    glutPostRedisplay();
}

void idle(){
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    player.createMove(currentTime-lastTime);
    player.foodCollision(&food.foodList);
    createMoveEnemies();
    lastTime = currentTime;
    glutPostRedisplay();
}

void insertEnemies(){
    for(int i = 0;i<numberOfEnemies;i++){
        enemy.createEnemy(pixelSize,pixelSize-14,map.randomBasePosition());
        listOfEnemies.push_back(enemy);
    }
}
void createMoveEnemies(){
    std::list<Enemy>::iterator iteratorEnemy;
    for(iteratorEnemy = listOfEnemies.begin(); iteratorEnemy != listOfEnemies.end(); ++iteratorEnemy){
        iteratorEnemy->createEnemyMove(currentTime-lastTime);
    }
}