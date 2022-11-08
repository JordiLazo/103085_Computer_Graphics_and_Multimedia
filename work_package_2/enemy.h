#include <GL/glut.h>
#include<list>
#include"position.h"
#include"map.h"

#define STILL 0
#define MOVE 1

#ifndef ENEMY
#define ENEMY
class Enemy {
    public:
        Position position;
        Map map;
        int pixelSize;
        float pixelSizeEnemy;
        float speed;
        int currentPositionX;
        int currentPositionY;
        float pixelSizePlayer;
        float centerPixel;
        float x;
        float y;
        int state;
        long timeRemaining;
        float vx,vy; //-- Velocity vector
        int key;
        Enemy();
        void createEnemy(int pixelSize, float pixelSizePlayer,Map map);
        void insertEnemies(int pixelSize, float pixelSizePlayer,Position position);
        void drawEnemies(list<Enemy> listOfEnemies);
        void createEnemyMove(long t);
        void moveEnemy();
        void checkValidEnemyMove(int key);
        int randomDirection();

};
#endif