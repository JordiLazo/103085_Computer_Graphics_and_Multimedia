#include"enemy.h"

Enemy::Enemy(){}
void Enemy::createEnemy(int pixelSize, float pixelSizeEnemy,Position position){
    this->state = MOVE;
    this->speed = 100.0;
    this->pixelSize = pixelSize;
    this->pixelSizePlayer = pixelSizeEnemy;
    this->currentPositionX = position.x;
    this->currentPositionY = position.y;
    this->position = position;
    this->centerPixel = (pixelSize/2) - (pixelSizeEnemy/2);
    this->x = this->currentPositionX*pixelSize + this->centerPixel;
    this->y = this->currentPositionY*pixelSize + this->centerPixel;

}
    
void Enemy::drawEnemies(list<Enemy> listOfEnemies){
    std::list<Enemy>::iterator enemiesIterator;
    for(enemiesIterator = listOfEnemies.begin(); enemiesIterator != listOfEnemies.end(); ++enemiesIterator){
        setColorPixel("GREEN");
        drawSquarePixel(enemiesIterator->x,enemiesIterator->y,enemiesIterator->pixelSizePlayer);
    }
}

void Enemy::createEnemyMove(long currentTime){
    if (this->state == MOVE){
        if(currentTime < timeRemaining) {
            this->x = x + vx*currentTime;
            this->y = y + vy*currentTime;
            timeRemaining -= currentTime;
            this->moveEnemy();
        } else if(currentTime >= timeRemaining) {
            this->x = x + vx*timeRemaining;
            this->y = y + vy*timeRemaining;
            this->moveEnemy();
            }else{
                this->moveEnemy();
            }
        }
    }
void Enemy::moveEnemy(){
    this->currentPositionY++;
    int destinationX = this->currentPositionX*this->pixelSize + this->centerPixel;
    int destinationY = this->currentPositionY*this->pixelSize + this->centerPixel;

    int distanceX = destinationX - x;
    int distanceY = destinationY - y;

    vx = distanceX/this->speed;
    vy = distanceY/this->speed;

    timeRemaining = this->speed;
}
bool Enemy::checkValidEnemyMove(){

}