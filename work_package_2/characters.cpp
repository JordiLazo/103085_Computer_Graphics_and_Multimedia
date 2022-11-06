#include "characters.h"

void Player::createPlayer(int pixelSize, float pixelSizePlayer, Position position){
    this-> state = STILL;
    this->speed = 250.0;
    this->gridx = position.x;
    this->gridy = position.y;

    this->dist = (pixelSize/2) - (pixelSizePlayer/2);
    this->x = this->gridx*pixelSize + this->dist;
    this->y = this->gridy*pixelSize + this->dist;

    this->pixelSize = pixelSize;
    this->pixelSizePlayer = pixelSizePlayer;

    this->map = map;
}
void Player::drawPlayer(int pixelSize){
    setColorPixel("YELLOW");
    drawSquarePixel(this->x,this->y,this->pixelSizePlayer);
}
Player::Player(){}

Position Player::startPosition(Map map){
    this->map = map;
    int start_x = -1;
    int start_y = -1;
    bool test = true;
    while (test) {
        start_x = rand() % this->map.rows;
        start_y = rand() % this->map.columns;
        if (this->map.array[start_x][start_y] == PATH){
            return Position(start_y, start_x);
            test = false;
        }
    }
}
