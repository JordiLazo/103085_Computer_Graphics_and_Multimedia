#include <GL/glut.h>
#include<list>
#include"position.h"
#include"map.h"

#define STILL 0
#define MOVE 1
#define ENEMIES 10

#ifndef ENEMY
#define ENEMY
class Enemy {
    public:
        Position position;
        int pixelSize;
        float pixelSizeEnemy;
        float speed;
        int currentPositionX;
        int currentPositionY;
        float pixelSizePlayer;
        float centerPixel;
        float x;
        float y;
        list<Enemy> listOfEnemies;
        int state;
        Enemy();
        void createEnemy(int pixelSize, float pixelSizePlayer,Position position);
        void insertEnemies(int pixelSize, float pixelSizePlayer,Position position);
        void drawEnemies();
        void generate_new_movement(long t);
        int get_random_direction();
        bool is_not_turn(int direction);
        void integrate_timer(long t);
};
#endif