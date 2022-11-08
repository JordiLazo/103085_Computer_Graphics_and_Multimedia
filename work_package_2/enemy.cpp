#include"enemy.h"

Enemy::Enemy(){}
Enemy::Enemy(float x, float y, float pixelSize){
    this->x = x;
    this->y = y;
    this->pixelSize = pixelSize;
    /*
    this->state = STILL;
    this->speed = 100.0;
    this->pixelSize = pixelSize;
    this->pixelSizePlayer = pixelSizePlayer;
    this->currentPositionX = position.x;
    this->currentPositionY = position.y;
    this->position = position;
    this->centerPixel = (pixelSize/2) - (pixelSizePlayer/2);
    this->x = this->currentPositionX*pixelSize + this->centerPixel;
    this->y = this->currentPositionY*pixelSize + this->centerPixel;
    */

}
void Enemy::insertEnemies(int pixelSize, float pixelSizePlayer,Position position){

    float foodSize = pixelSize/4;//pixel foodSize
    float foodSizeCenter = foodSize/4;//center of the pixel foodSize
    float centerPixelSize = pixelSize/2;
    for(int i = 0; i < ENEMIES; i++){
        float foodPositionJ = (position.x * pixelSize) + centerPixelSize - foodSizeCenter;
        float foodPositionI = (position.y * pixelSize) + centerPixelSize - foodSizeCenter;
        listOfEnemies.push_back(Enemy(foodPositionJ, foodPositionI, foodSize));
        }
    }
void Enemy::drawEnemies(){
    list<Enemy>::iterator enemy;
    for (enemy = this->listOfEnemies.begin(); enemy != this->listOfEnemies.end(); ++enemy){
        setColorPixel("BLACK");
        drawSquarePixel(enemy->x, enemy->y, enemy->pixelSizePlayer);
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

int Enemy::get_random_direction(){
    int directions[] = {GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_LEFT, GLUT_KEY_RIGHT};
    return directions[rand() % 4];
}

bool Enemy::is_not_turn(int direction){
    switch (direction) {
        case GLUT_KEY_UP:
            return this->direction != GLUT_KEY_DOWN;
        case GLUT_KEY_DOWN:
            return this->direction != GLUT_KEY_UP;
        case GLUT_KEY_LEFT:
            return this->direction != GLUT_KEY_RIGHT;
        case GLUT_KEY_RIGHT:
            return this->direction != GLUT_KEY_LEFT;
    }
    return false;
}

void Enemy::integrate_timer(long t){
    switch (this->behave_state) {
        case HOUSE:
            if (this->timer + t > exit_timer){
                this->behave_state = CHASE;
                this->timer = 0;
            }
            break;
        case SCATTER:
            if (this->timer + t > scatter_timer){
                this->behave_state = CHASE;
                this->color = RED;
                this->timer = 0;
            }
            break;
        case CHASE:
            if (this->timer + t > chase_timer){
                this->behave_state = SCATTER;
                this->color = PINK;
                int xs[] = {0,map.n_cols};
                int ys[] = {0,map.n_rows};
                this->corner_x = xs[rand() % 2];
                this->corner_y = ys[rand() % 2];
                this->timer = 0;
            }
            break;
    }
    this->timer += t;
}
*/