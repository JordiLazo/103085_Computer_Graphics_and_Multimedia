#include <GL/glut.h>
#include<iostream>
#include "light.h"

int light_offset = 0;

// parameter: GL_AMBIENT, GL_SPECULAR, GL_DIFFUSE
void set_lighting_color(int light_id, int parameter, int color_id){
    GLfloat color[4];
    switch (color_id) {
        case RED_LIGHT:
            color[0]=1.0; color[1]=0.0; color[2]=0.0; color[3]=1;
            break;
        case BLUE_LIGHT:
            color[0]=0.0; color[1]=0.0; color[2]=1.0; color[3]=1;
            break;
        case WHITE_LIGHT:
            color[0]=1.0; color[1]=1.0; color[2]=1.0; color[3]=1;
            break;
        case AMBIENT_LIGHT:
            color[0]=0.05; color[1]=0.05; color[2]=0.05; color[3]=1;
            break;
    }
    glLightfv(light_id,parameter,color);
}

void set_light_position(int light_id, int x, int y, int z){
    GLint position[4];
    position[0]=x; position[1]=y; position[2]=z; position[3]=1;
    glLightiv(light_id,GL_POSITION,position);
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
    //glLightf(GL_LIGHT2,GL_LINEAR_ATTENUATION,0.005);
    //glLightf(GL_LIGHT2,GL_QUADRATIC_ATTENUATION,0.0);
    set_light_position(this->light_id, (int) this->x, (int) this->y, (int) this->z);

    set_lighting_color(this->light_id, GL_SPECULAR, this->color);
    set_lighting_color(this->light_id, GL_DIFFUSE, this->color);

    set_light_direction(this->light_id, lightX, lightY, lightZ);

    glLighti(this->light_id,GL_SPOT_CUTOFF,30);
    glEnable(this->light_id);
}

void Light::setPlayerLight(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void Light::setDirectionPlayerLight(int array[]){
    this->lightX = array[0];
    this->lightY = array[1];
    this->lightZ = array[2];
}
