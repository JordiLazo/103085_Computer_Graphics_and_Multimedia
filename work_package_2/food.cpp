#include<GL/glut.h>
#include<iostream>
#include<vector>
#include"food.h"

Food::Food(){};
void Food::setPosition(int x,int y){
    this->x = x;
    this->y = y;
}
void Food::draw(){
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2i(x-6,y-6);
    glVertex2i(x+6,y-6);
    glVertex2i(x+6,y+6);
    glVertex2i(x-6,y+6);
    glEnd();
}