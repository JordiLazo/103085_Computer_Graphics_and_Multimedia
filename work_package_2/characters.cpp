#include "characters.h"

Player::Player(){}
void Player::createPlayer(int pixelSize, float pixelSizePlayer, Position position){
    this->state = STILL;
    this->speed = 100.0;
    this->pixelSize = pixelSize;
    this->pixelSizePlayer = pixelSizePlayer;
    this->map = map;
    this->currentPositionX = position.x;
    this->currentPositionY = position.y;
    this->centerPixel = (pixelSize/2) - (pixelSizePlayer/2);
    this->x = this->currentPositionX*pixelSize + this->centerPixel;
    this->y = this->currentPositionY*pixelSize + this->centerPixel;
}
void Player::drawPlayer(int pixelSize){
    setColorPixel("YELLOW");
    drawSquarePixel(this->x,this->y,this->pixelSizePlayer);
}

Position Player::startPosition(Map map){
    this->map = map;
    bool validPosition = true;
    while (validPosition) {
        int x = rand() % this->map.rows;
        int y = rand() % this->map.columns;
        if (this->map.array[x][y] == PATH){
            validPosition = false;
            printf("X:%d\n",x);
            printf("Y:%d\n",y);
            return Position(y, x);
        }
    }
}

void Player::handleKeyboard(int key){
    if (this->state == STILL || this->state == MOVE){
        if (this->validMove(key)){
            this->direction = key;
            this->key = key;
            this->move(key);
        }
    }
}

void Player::move(int key){
    this->state = MOVE;

    switch (direction) {
        case GLUT_KEY_UP:
            this->currentPositionY--;
            break;
        case GLUT_KEY_DOWN:
            this->currentPositionY++;
            break;
        case GLUT_KEY_LEFT:
            this->currentPositionX--;
            break;
        case GLUT_KEY_RIGHT:
            this->currentPositionX++;
            break;
    }

    int destination_x = this->currentPositionX*this->pixelSize + this->centerPixel;
    int destination_y = this->currentPositionY*this->pixelSize + this->centerPixel;

    int dx = destination_x - x;
    int dy = destination_y - y;

    vx = dx/this->speed;
    vy = dy/this->speed;

    time_remaining = this->speed;

}
bool Player::validMove(int key){
    switch (key) {
        case GLUT_KEY_UP:
        if (map.array[this->currentPositionY-1][this->currentPositionX] == PATH){
            this->isOut = true;
            return true;
        } else if (!this->isOut && map.array[this->currentPositionY-1][this->currentPositionX] == CENTERWALL){
            return true;
        }
        break;
    case GLUT_KEY_DOWN:
        if (map.array[this->currentPositionY+1][this->currentPositionX] == PATH){
            this->isOut = true;
            return true;
        } else if (!this->isOut && map.array[this->currentPositionY+1][this->currentPositionX] == CENTERWALL){
            return true;
        }
        break;
    case GLUT_KEY_LEFT:
        if (map.array[this->currentPositionY][this->currentPositionX-1] == PATH){
            this->isOut= true;
            return true;
        } else if (!this->isOut&& map.array[this->currentPositionY][this->currentPositionX-1] == CENTERWALL){
            return true;
        }
        break;
    case GLUT_KEY_RIGHT:
        if (map.array[this->currentPositionY][this->currentPositionX+1] == PATH){
            this->isOut= true;
            return true;
        } else if (!this->isOut && map.array[this->currentPositionY][this->currentPositionX+1] == CENTERWALL){
            return true;
        }
        break;
    }
    return false;
}

void Player::integrate(long t){
    if (this->state == MOVE){
        if(t < time_remaining) {
            this->x = x + vx*t;
            this->y = y + vy*t;
            time_remaining -= t;
        } else if(t >= time_remaining) {
            this->x = x + vx*time_remaining;
            this->y = y + vy*time_remaining;
            if (this->validMove(this->key)){
                this->direction = this->key;
                this->move(this->key);
            }else if(this->validMove(this->direction)){
                this->move(this->direction);
            }else{
                this->state = STILL;
                this->direction = -1;
                this->key = -1;
            }
        }
}
}