#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include<time.h>
#include<list>
#include<tgmath.h>
#include"graphic.h"
#include"map.h"
#include"agent.h"
#include "food.h"



//-------------------------
// OpenGL functions
void display();

//-------------------------

// Maze size (cells)
int ROWS;
int COLS;

// Max window size (pixels)
int MAX_WIDTH = 1000;
int MAX_HEIGHT = 600;

// min number of cols and rows
int MIN_ROWS_COLS = 15;

// Final window size and projection size (pixels)
int WIDTH;
int HEIGHT;

// Size of a corridor square (pixels)
int sq_size;

long last_t = 0;

Agent pacman;
list<Ghost> ghosts;
list<Food> foodList;


// Map object, not initialized
Map map;

void put_food();
void draw_food();
void check_collisions();


int main(int argc, char *argv[]) {
    if (argc < 3){
        printf("Usage: ./pacman <half_of_rows> <half_of_columns>\n");
        exit(-1);
    }

    srand(clock());

    // Calculate the number of rows and cols
    ROWS = atoi(argv[1]);
    ROWS = (ROWS % 2 == 0 ? ROWS + 1 : ROWS) * 2+1;
    COLS = atoi(argv[2]);
    COLS = (COLS % 2 == 0 ? COLS + 1 : COLS) * 2 + 1;
    if(ROWS < MIN_ROWS_COLS || COLS <  MIN_ROWS_COLS) {
        printf("The number of half_of_columns and half_of_rows must be greater Than or Equal to %d\n", MIN_ROWS_COLS);
        exit(0);
    }


    map.generate(ROWS,COLS);
    map.print_map();

    // init the windows
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);

    sq_size = min(MAX_WIDTH / COLS, MAX_HEIGHT / ROWS);

    WIDTH = sq_size * COLS;
    HEIGHT = sq_size * ROWS;
    // Generar fantasmes aqui

    pair<int, int> start_positions = map.start_position();
    pacman.initialize(sq_size, sq_size-7, start_positions.first, start_positions.second, map);
    printf("Px:%d\n",start_positions.first);
    printf("Py:%d\n",start_positions.second);
    pacman.color = ORANGE;

    // calculate number of ghosts
    int n_ghosts =  max(COLS, ROWS) / 5;
    for(int i = 0; i < n_ghosts; i++){
        pair<int, int> start_positions = map.base_start_position();
        Ghost ghost;
        ghost.initialize(sq_size, sq_size-7, start_positions.first, start_positions.second, map);
        ghost.color = RED;
        ghost.is_out = false;
        ghost.is_autonomous = true;
        ghost.timer = 0;
        ghost.exit_timer = 10000 * i;
        ghost.chase_timer = 10000;
        ghost.scatter_timer = 8000;
        ghosts.push_back(ghost);
    }
    // put food
    put_food();

    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Pac-Man");

    glutDisplayFunc(display);


    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,WIDTH-1,HEIGHT-1,0);

    glutMainLoop();
    return 0;
}

void display(){
    int i, j;

    // Set wall color as grey
    glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    map.draw(sq_size);
    // Draw food
    draw_food();

    // Draw agents
    pacman.draw();

    // Draw ghosts
    std::list<Ghost>::iterator ghost;
    for(ghost = ghosts.begin(); ghost != ghosts.end(); ++ghost){
        ghost->draw();
    }

    glutSwapBuffers();

}


void put_food() {
    // calculate food size
    float food_size = sq_size/4;
    food_size = ((int)food_size % 2 == 0) ? food_size +1: food_size;
    for (int y=0; y < map.n_rows; y++) {
        for (int x=0; x < map.n_cols; x++) {
            if(map.mesh[y][x] == CELL_VISITED){
                // calculate cell  position
                float cell_origin_x = x * sq_size;
                float cell_origin_y = y * sq_size;
                // calculate cell center
                float center_d = sq_size / 2;
                float food_d = food_size /2;
                // Calculate food cosition
                float food_x = cell_origin_x + center_d - food_d;
                float food_y = cell_origin_y + center_d - food_d;
                foodList.push_back(Food(food_x, food_y, food_size));
            }
        }
    }
}

void draw_food() {
    std::list<Food>::iterator food;
    for (food = foodList.begin(); food != foodList.end(); ++food){
        food->draw();
    }
}