#include "characters.h"

void Player::createPlayer(int pixelSize, float pixelSizePlayer, Position position){
    setColorPixel("YELLOW");
    drawSquarePixel((float) position.x,(float)position.y,pixelSizePlayer);
}