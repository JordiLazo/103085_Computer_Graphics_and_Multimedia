#include<GL/glut.h>
#include<iostream>
#include<vector>
#include"food.h"
#include"draw.h"

Food::Food(float x, float y, float pixels){
    this->x = x;
    this->y = x;
    this->pixels = pixels;

};
void Food::draw(){
    set_3f_color(RED);
    draw_squaref(x, y, pixels);
}