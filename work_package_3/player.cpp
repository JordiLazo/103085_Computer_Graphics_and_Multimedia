#include "player.h"

Player::Player(){}
void Player::createPlayer(int pixelSize, float pixelSizePlayer, Map map){
    this->state = QUIET;
    this->speed = 100.0;
    this->pixelSize = pixelSize;
    this->map = map;
    this->pixelSizePlayer = pixelSizePlayer;
    this->currentPositionX = this->startPosition(this->map).x;
    this->currentPositionY = this->startPosition(this->map).y;
    this->centerPixel = pixelSize - pixelSizePlayer;
    this->x = this->currentPositionX*pixelSize + this->centerPixel;
    this->y = this->currentPositionY*pixelSize + this->centerPixel;
}
void Player::drawPlayer(){
    //setColorPixel("ORANGE");
    set_texture(PLAYERTEXTURE);
    draw_prism_textured(this->x,0,this->y,this->pixelSizePlayer,this->pixelSizePlayer,this->pixelSizePlayer);
}

Position Player::startPosition(Map map){
    this->map = map;
    srand(clock());
    bool validPosition = false;
    while (!validPosition) {
        int x = rand() % this->map.rows;
        int y = rand() % this->map.columns;
        if (this->map.array[x][y] == PATH){
            validPosition = true;
            return Position(y, x);
        }
    }
    return Position(10,10);
}

void Player::handleKeyboard(int key){
    if (this->state == QUIET || this->state == MOVE){
        if (this->checkValidMove(key)){
            this->key = key;
            this->move(key);
        }
    }
}

void Player::move(int key){
    this->state = MOVE;
    if(key == GLUT_KEY_UP){
        this->currentPositionY--;
    }
    if(key == GLUT_KEY_DOWN){
        this->currentPositionY++;
    }
    if(key == GLUT_KEY_LEFT){
        this->currentPositionX--;
    }
    if(key == GLUT_KEY_RIGHT){
        this->currentPositionX++;
    }

    int destinationX = this->currentPositionX*this->pixelSize + this->centerPixel;
    int destinationY = this->currentPositionY*this->pixelSize + this->centerPixel;

    int distanceX = destinationX - x;
    int distanceY = destinationY - y;

    vx = distanceX/this->speed;
    vy = distanceY/this->speed;

    timeRemaining = this->speed;

}
bool Player::checkValidMove(int key){
    if(key == GLUT_KEY_UP){
        return checkUpMove(key);
    }
    if(key == GLUT_KEY_DOWN){
        return checkDownMove(key);
    }
    if(key == GLUT_KEY_LEFT){
        return checkLeftMove(key);
    }
    if(key == GLUT_KEY_RIGHT){
        return checkRightMove(key);
    }else{
        return false;
    }
}

void Player::createMove(long currentTime){
    if (this->state == MOVE){
        if(currentTime < timeRemaining) {
            this->x = x + vx*currentTime;
            this->y = y + vy*currentTime;
            timeRemaining -= currentTime;
        } else if(currentTime >= timeRemaining) {
            this->x = x + vx*timeRemaining;
            this->y = y + vy*timeRemaining;
            if (this->checkValidMove(this->key)){
                this->move(this->key);
            }else{
                this->state = QUIET;
            }
        }
    }
}

bool Player::checkUpMove(int key){
    if (map.array[this->currentPositionY-1][this->currentPositionX] == PATH && !(map.array[this->currentPositionY-1][this->currentPositionX] == CENTERWALL)){
        this->validMove = true;
        return true;
    }else{
        return false;
    }
}

bool Player::checkDownMove(int key){
    if (map.array[this->currentPositionY+1][this->currentPositionX] == PATH && !(map.array[this->currentPositionY+1][this->currentPositionX] == CENTERWALL)){
        this->validMove = true;
        return true;
    } else{
        return false;
    }
}
bool Player::checkLeftMove(int key){
    if (map.array[this->currentPositionY][this->currentPositionX-1] == PATH && !(map.array[this->currentPositionY][this->currentPositionX-1] == CENTERWALL)){
        this->validMove= true;
        return true;
    } else{
        return false;
    }
}
bool Player::checkRightMove(int key){
    if (map.array[this->currentPositionY][this->currentPositionX+1] == PATH && !(map.array[this->currentPositionY][this->currentPositionX+1] == CENTERWALL)){
        this->validMove= true;
        return true;
    } else{
        return false;
    }
}
void Player::foodCollision(list<Food> *foodList){
    std::list<Food>::iterator foodItem;
    for (foodItem = foodList->begin(); foodItem != foodList->end(); ++foodItem){
        Position playerPosition = Position(this->x, this->y);
        Position foodPosition = Position(foodItem->x, foodItem->y);
        if(checkFoodCollision(playerPosition, foodPosition)) {
            foodItem = foodList->erase(foodItem);
        }
    }
}
bool Player::checkFoodCollision(Position playerPosition, Position foodPosition){
    float distancePixels = pixelSize/2;
    float distanceX = abs(playerPosition.x - foodPosition.x);
    float distanceY = abs(playerPosition.y - foodPosition.y);
    if(distanceX + distanceY <= distancePixels){
        return true;
    }else{
        return false;
    }
}