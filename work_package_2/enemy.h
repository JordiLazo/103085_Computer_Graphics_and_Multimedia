#include <GL/glut.h>
#include<list>
#include"position.h"
#include"map.h"

#define ENEMIES 10


#ifndef ENEMY
#define ENEMY
class Enemy {
    public:
    list<Enemy> listOfEnemies;
    void generateEnemies();
    void insertEnemies();
    void generate_new_movement(long t);
    int get_random_direction();
    bool is_not_turn(int direction);
    void integrate_timer(long t);

};
#endif