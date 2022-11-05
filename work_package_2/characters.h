#include <GL/glut.h>
#include "map.h"

#define STILL 0
#define MOVING_BETWEEN 1
#define REACHED 2

#define HOUSE 0
#define SCATTER 1
#define CHASE 2

using namespace std;

class Player {
    public:
        Player(){};
        void createPlayer(int pixelSize, float pixelSizePlayer,Position position);
};