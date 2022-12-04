#include"enemy.h"

Enemy::Enemy(){}
void Enemy::createEnemy(int pixelSize, float pixelSizeEnemy,Map map){
    this->state = QUIET;
    this->speed = 200.0;
    this-> map = map;
    this->pixelSize = pixelSize;
    this->pixelSizeEnemy = pixelSizeEnemy;
    this->currentPositionX = map.randomBasePositionEnemy().x;
    this->currentPositionY = map.randomBasePositionEnemy().y;
    this->position = position;
    this->centerPixel = (pixelSize/2) - (pixelSizeEnemy/2);
    this->x = this->currentPositionX*pixelSize + this->centerPixel;
    this->y = this->currentPositionY*pixelSize + this->centerPixel;

}

void Enemy::drawEnemies(list<Enemy> listOfEnemies){
    std::list<Enemy>::iterator enemy;
    for(enemy = listOfEnemies.begin(); enemy != listOfEnemies.end(); ++enemy){
        setTexture(ENEMYTEXTURE);
        drawTextured3dRectangle(enemy->x,0,enemy->y,enemy->pixelSizeEnemy,enemy->pixelSizeEnemy,enemy->pixelSizeEnemy);
    }
}

void Enemy::handleKeyboard(int key){
    if (this->state == QUIET){
        if (this->checkValidEnemyMove(key)){
            this->key = key;
            this->moveEnemy(key);
        }
    }else if(this->state == MOVE) {
        this->key = key;
    }
}


void Enemy::createEnemyMove(long currentTime){
    if (this->state == MOVE){
        if(currentTime < timeRemaining) {
            this->x = x + vx*currentTime;
            this->y = y + vy*currentTime;
            timeRemaining -= currentTime;
        } else if(currentTime >= timeRemaining) {
            this->x = x + vx*timeRemaining;
            this->y = y + vy*timeRemaining;
            if (this->checkValidEnemyMove(this->key)){
                this->moveEnemy(this->key);
            }else{
                this->state = MOVE;
            }
        }
    }
}

void Enemy::moveEnemy(int key){
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

int Enemy::randomDirection(){
    int directions[] = {GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_LEFT, GLUT_KEY_RIGHT};
    int randomIndex = rand()%4;
    return directions[randomIndex];
}

bool Enemy::checkValidEnemyMove(int key){
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

bool Enemy::checkUpMove(int key){
    if (map.array[this->currentPositionY-1][this->currentPositionX] == PATH){
        this->validMove = true;
        return true;
    } else if (!this->validMove && map.array[this->currentPositionY-1][this->currentPositionX] == BASEPATH){
        return true;
    }else{
        return false;
    }
}

bool Enemy::checkDownMove(int key){
    if (map.array[this->currentPositionY+1][this->currentPositionX] == PATH){
        this->validMove = true;
        return true;
    } else if (!this->validMove && map.array[this->currentPositionY+1][this->currentPositionX] == BASEPATH){
        return true;
    }else{
        return false;
    }
}
bool Enemy::checkLeftMove(int key){
    if (map.array[this->currentPositionY][this->currentPositionX-1] == PATH){
        this->validMove = true;
        return true;
    } else if (!this->validMove && map.array[this->currentPositionY][this->currentPositionX-1] == BASEPATH){
        return true;
    }else{
        return false;
    }
}
bool Enemy::checkRightMove(int key){
    if (map.array[this->currentPositionY][this->currentPositionX+1] == PATH){
        this->validMove = true;
        return true;
    } else if (!this->validMove && map.array[this->currentPositionY][this->currentPositionX+1] == BASEPATH){
        return true;
    }else{
        return false;
    }
}
