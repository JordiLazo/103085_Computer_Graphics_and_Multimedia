#include"enemy.h"

void Enemy::generateEnemies(){
    for(int i = 0; i <= ENEMIES; i++){

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