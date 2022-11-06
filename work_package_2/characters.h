#include <GL/glut.h>
#include "map.h"
#include "position.h"

#define STILL 0
#define MOVE 1
#define REACHED 2

#define HOUSE 0
#define SCATTER 1
#define CHASE 2

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
    bool isOut;
    float vx,vy; //-- Velocity vector
    long time_remaining;
    Player();
    void createPlayer(int pixelSize, float pixelSizePlayer,Position position);
    void drawPlayer(int pixelSize);
    Position startPosition(Map map);
    void handleKeyboard(int key);
    void move(int key);
    bool validMove(int key);
    void integrate(long t);
};
#endif