#include<GL/glut.h>
#include<iostream>
#include"draw.h"
#include"food.h"
#include<list>

#define COLUMNS 22
#define ROWS 21
#define WIDTH 1200
#define HEIGHT 700


int pixels;
list<Food> foodList;
void putFood();
void drawFood();

void display();

GenerateMap *map;

int main(int argc, char *argv[]) {
    pixels = min(WIDTH/COLUMNS,HEIGHT/ROWS);
    GenerateMap newMap(COLUMNS,ROWS);
    newMap.printTable();
    map = &newMap;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    putFood();

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
    drawFood();
    drawVector(WIDTH,HEIGHT,*map);
    
    glutSwapBuffers();




}
void putFood(){
        // calculate food size
    float foodSize = pixels/4;
    foodSize = ((int)foodSize % 2 == 0) ? foodSize +1: foodSize;
    for (int i=0; i < map->rows; i++) {
        for (int j=0; j < map->columns; j++) {
            if(map->array[i][j] == PATH){
                // calculate cell  position
                float cell_origin_x = j * pixels;
                float cell_origin_y = i * pixels;
                // calculate cell center
                float center_d = pixels / 2;
                float food_d = pixels/2;
                // Calculate food cosition
                float food_x = cell_origin_x + center_d - food_d;
                float food_y = cell_origin_y + center_d - food_d;
                foodList.push_back(Food(food_x, food_y, foodSize));
            }
        }
    }
}

void drawFood(){
    std::list<Food>::iterator food;
    for (food = foodList.begin(); food != foodList.end(); ++food){
        food->draw();
    }
}