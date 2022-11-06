#include <GL/glut.h>
#include "map.h"
#include "position.h"

#define STILL 0
#define MOVING_BETWEEN 1
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
    int gridx;
    int gridy;
    float dist;
    Player();
    void createPlayer(int pixelSize, float pixelSizePlayer,Position position);
    void drawPlayer(int pixelSize);
    Position startPosition(Map map);
};
#endif