#include"enemy.h"

Enemy::Enemy(){}
void Enemy::createEnemy(int pixelSize, float pixelSizeEnemy,Map map){
    this->state = MOVE;
    this->speed = 500.0;
    this-> map = map;
    this->pixelSize = pixelSize;
    this->pixelSizePlayer = pixelSizeEnemy;
    this->currentPositionX = map.randomBasePosition().x;
    this->currentPositionY = map.randomBasePosition().y;
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
    this->state = MOVE;
    this->checkValidEnemyMove(this->randomDirection());
    int destinationX = this->currentPositionX*this->pixelSize + this->centerPixel;
    int destinationY = this->currentPositionY*this->pixelSize + this->centerPixel;

    int distanceX = destinationX - x;
    int distanceY = destinationY - y;

    vx = distanceX/this->speed;
    vy = distanceY/this->speed;

    timeRemaining = this->speed;
}

int Enemy::randomDirection(){
    int directions[] = {GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_LEFT, GLUT_KEY_RIGHT};
    int randomIndex = rand()%4;
    return directions[randomIndex];
}

void Enemy::checkValidEnemyMove(int key){
    if(key == GLUT_KEY_UP){
        if (!(map.array[this->currentPositionY-1][this->currentPositionX] == WALL || map.array[this->currentPositionY-1][this->currentPositionX] == CENTERWALL)){
            this->currentPositionY--;
            }
    }
    if(key == GLUT_KEY_DOWN){
        if (!(map.array[this->currentPositionY+1][this->currentPositionX] == WALL || map.array[this->currentPositionY+1][this->currentPositionX] == CENTERWALL)){
        this->currentPositionY++;
        }
    }
    if(key == GLUT_KEY_LEFT){
        if (!(map.array[this->currentPositionY][this->currentPositionX-1] == WALL || map.array[this->currentPositionY][this->currentPositionX-1] == CENTERWALL)){
            this->currentPositionX--;
        }
    }
    if(key == GLUT_KEY_RIGHT){
        if (!(map.array[this->currentPositionY][this->currentPositionX+1] == WALL || map.array[this->currentPositionY][this->currentPositionX+1] == CENTERWALL)){
            this->currentPositionX++;
        }
    }
}
/*
void Enemy::generate_new_movement(long t){
    if (t + this->timer_elapsed > this->random_timer){
        this->timer_elapsed = 0;
        int new_direction = this->get_random_direction();
        this->treat_input(new_direction);
    }else{
        this->timer_elapsed += t;
    }
}
*/