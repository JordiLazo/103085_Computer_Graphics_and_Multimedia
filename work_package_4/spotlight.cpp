#include <GL/glut.h>
#include<iostream>
#include "spotlight.h"

Light::Light(){}

void Light::illuminati() {
    createLight(this->x, this->y, this->z);
    directionLight(this->lightX, this->lightY, this->lightZ);
    glLighti(GL_LIGHT1,GL_SPOT_CUTOFF,30);
    glEnable(GL_LIGHT1);
}
void Light::createLight(int x, int y, int z){
    GLint position[4];
    position[0]=x; position[1]=y; position[2]=z; position[3]=1;
    glLightiv(GL_LIGHT1,GL_POSITION,position);
}

void Light::directionLight(int x, int y, int z){
    GLint position[4];
    position[0]=x; position[1]=y; position[2]=z; position[3]=1;
    glLightiv(GL_LIGHT1,GL_SPOT_DIRECTION,position);
}

void Light::setCharacterLight(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void Light::setDirectionCharacterLight(int array[]){
    this->lightX = array[0];
    this->lightY = array[1];
    this->lightZ = array[2];
}
