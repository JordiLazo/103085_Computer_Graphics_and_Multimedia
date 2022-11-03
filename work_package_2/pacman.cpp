#include<GL/glut.h>
#include<iostream>
#include"draw.h"
#include"food.h"
#include"generateMap.h"
#include<list>

#define COLUMNS 40
#define ROWS 40
#define WIDTH 1400
#define HEIGHT 700


int pixels;
list<Food> foodList;
void putFood();
void drawFood();

void display();

GenerateMap *map;

int main(int argc, char *argv[]) {
    
    
    GenerateMap newMap(COLUMNS,ROWS);
    newMap.printTable();
    map = &newMap;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    pixels = min(WIDTH/COLUMNS, HEIGHT/ROWS);
    printf("pixels:%d\n",pixels);
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
    map->draw(pixels);
    drawFood();
    
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
                float cell_origin_j = j * pixels;
                float cell_origin_i = i * pixels;
                // calculate cell center
                float center_d = pixels / 2;
                float food_d = foodSize/2;
                // Calculate food cosition
                float food_j = cell_origin_j + center_d - food_d;
                float food_i = cell_origin_i + center_d - food_d;
                foodList.push_back(Food(food_j, food_i, foodSize));
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