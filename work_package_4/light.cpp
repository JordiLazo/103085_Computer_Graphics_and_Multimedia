#include <GL/glut.h>
#include<iostream>
#include "light.h"

int light_offset = 0;

// parameter: GL_AMBIENT, GL_SPECULAR, GL_DIFFUSE
void createLight(int x, int y, int z){
    GLint position[4];
    position[0]=x; position[1]=y; position[2]=z; position[3]=1;
    glLightiv(SPOTLIGHT,GL_POSITION,position);
}

void set_light_direction(int light_id, int x, int y, int z){
    GLint position[4];
    position[0]=x; position[1]=y; position[2]=z; position[3]=1;
    glLightiv(light_id,GL_SPOT_DIRECTION,position);
}

void set_material(float r, float g, float b){
    GLfloat material[4];
    material[0]=r; material[1]=g; material[2]=b; material[3]=1.0;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material);
}

Light::Light(){}
void Light::illuminati() {
    createLight(this->x, this->y, this->z);
    set_light_direction(SPOTLIGHT, lightX, lightY, lightZ);
    glLighti(SPOTLIGHT,GL_SPOT_CUTOFF,30);
    glEnable(SPOTLIGHT);
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
