#include<GL/glut.h>
#include<iostream>
#include"map.h"
#include"player.h"

//-----------------------------------MAP SIZE-----------------------------------//
#define COLUMNS 15
#define ROWS 15

//-----------------------------------OPEN GL-----------------------------------//
void display();
void keyboard(int key, int x, int y);
void idle();

//-----------------------------------WINDOW SIZE-----------------------------------//
#define WIDTH 1400
#define HEIGHT 700

//-----------------------------------GLOBAL FUNCTIONS-----------------------------------//
void food_collision();
bool have_collision(Position obj1, Position obj2);

//-----------------------------------GLOBAL VARIBALES-----------------------------------//
int pixelSize; //pixels size of each position of the map
Map map;
Player player;
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
    map.insertFood(pixelSize);
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
    map.drawFood(pixelSize);
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
    food_collision();
    lastTime = currentTime;
    glutPostRedisplay();
}
void food_collision() {
    Food *food_to_remove = 0;
    float dist = pixelSize / 2;
    std::list<Food>::iterator food;
    for (food = map.foodList.begin(); food != map.foodList.end(); ++food){
        Position obj1 = Position(player.x, player.y);
        Position obj2 = Position(food->x, food->y);
        if(have_collision(obj1, obj2)) {
            food_to_remove = &(*food);
        }
    }
    if (food_to_remove != 0){
        map.foodList.remove(*food_to_remove);
    }
}
bool have_collision(Position obj1, Position obj2) {
    int dist = pixelSize/2;
    float dx = abs(obj1.x - obj2.x);
    float dy = abs(obj1.y - obj2.y);
    return dx  +  dy <= dist;
}