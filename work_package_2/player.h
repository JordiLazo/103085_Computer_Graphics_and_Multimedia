#include <GL/glut.h>
#include<list>
#include"position.h"
#include"map.h"
#include"food.h"

#define STILL 0
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
    int x;
    int y;
    int state;
    float speed;
    int currentPositionX;
    int currentPositionY;
    float centerPixel;
    int key;
    int direction;
    bool validMove;
    float vx,vy; //-- Velocity vector
    long timeRemaining;
//-----------------------------------FUNCTIONS-----------------------------------//
    Player();
    void createPlayer(int pixelSize, float pixelSizePlayer,Map map, Position startPosition);
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
    bool checkFoodCollision(Position object1, Position object2);
};
#endif