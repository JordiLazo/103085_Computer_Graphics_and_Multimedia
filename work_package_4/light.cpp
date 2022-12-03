#include <GL/glut.h>
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

void set_directional_light(int light_id, int x, int y, int z){
    GLint position[4];
    position[0]=x; position[1]=y; position[2]=z; position[3]=0;
    glLightiv(light_id,GL_POSITION,position);
}

void set_material(float r, float g, float b){
    GLfloat material[4];
    material[0]=r; material[1]=g; material[2]=b; material[3]=1.0;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material);
}

void set_material_id(int material_id){
    GLfloat material[4];
    switch (material_id) {
        case FULVOUS_MATERIAL:
            material[0]=scale_l(226); material[1]=scale_l(139); material[2]=scale_l(19); material[3]=1.0;
            break;
        case RED_CRAYOLA_MATERIAL:
            material[0]=scale_l(234); material[1]=scale_l(23); material[2]=scale_l(68); material[3]=1.0;
            break;
        case DARK_GREEN_MATERIAL:
            material[0]=scale_l(52); material[1]=scale_l(76); material[2]=scale_l(17); material[3]=1.0;
            break;
    }
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material);
}

double scale_l(int input){
    int input_start = 0.0;
    int input_end = 255.0;
    double output_start = 0.0;
    double output_end = 1.0;
    return output_start + ((output_end - output_start) / (input_end - input_start)) * (input - input_start);
}

void set_light_offset(int offset){
    light_offset = offset;
}

//---------------FLASHLIGHT---------------

Light::Light(){}

void Light::draw() {
    //glLightf(GL_LIGHT2,GL_LINEAR_ATTENUATION,0.005);
    //glLightf(GL_LIGHT2,GL_QUADRATIC_ATTENUATION,0.0);
    set_light_position(this->light_id, (int) this->x, (int) this->y, (int) this->z);

    set_lighting_color(this->light_id, GL_SPECULAR, this->color);
    set_lighting_color(this->light_id, GL_DIFFUSE, this->color);

    set_light_direction(this->light_id, dx, dy, dz);

    glLighti(this->light_id,GL_SPOT_CUTOFF,30);
    glEnable(this->light_id);
}

void Light::set_position(float x, float y, float z){
    this->x = (int) x+light_offset;
    this->y = (int) y;
    this->z = (int) z+light_offset;
}

void Light::set_direction(int dx, int dy, int dz){
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}
