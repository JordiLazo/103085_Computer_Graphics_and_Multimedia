#include <GL/glut.h>
#include<list>
#include"position.h"
#include"map.h"
#include"food.h"
#include"enemy.h"
#include"spotlight.h"

#define QUIET 0
#define MOVE 1

using namespace std;

#ifndef PLAYER
#define PLAYER

class Player {
    public:
//-----------------------------------ATTRIBUTES-----------------------------------//
    Position position;
    int pixelSize;
    float pixelSizePlayer;
    Map map;
    float x;
    float y;
    int state;
    float speed;
    int currentPositionX;
    int currentPositionY;
    Position currentPosition;
    float centerPixel;
    int key;
    int direction;
    bool validMove;
    float vx,vy; //-- Velocity vector
    long timeRemaining;
    Light light;
//-----------------------------------FUNCTIONS-----------------------------------//
    Player();
    void createPlayer(int pixelSize, float pixelSizePlayer,Map map, Position startingPosition);
    void drawPlayer();
    Position startPosition(Map map);
    void handleKeyboard(int key);
    void move(int key);
    bool checkValidMove(int key);
    bool checkUpMove(int key);
    bool checkDownMove(int key);
    bool checkLeftMove(int key);
    bool checkRightMove(int key);
    void createMove(long t);
    void foodCollision(list<Food> *foodList);
    void enemyCollision(list<Enemy> *enemyList);
    bool checkCollition(Position object1, Position object2);
};
#endif