#include<GL/glut.h>
#include<iostream>
#include<vector>
#include"food.h"
#include"draw.h"

Food::Food(float j, float i, float pixels){
    this->j = j;
    this->i = i;
    this->pixels = pixels;

};
void Food::draw(){
    set_3f_color(GREEN);
    draw_squaref(j, i, pixels);
}