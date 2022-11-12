#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "food.h"
#include "graphic.h"
#include"texture.h"


Food::Food(float x, float y, float size) {
    this->x = x;
    this->y = y;
    this->size = size;
}


void Food::draw() {
    //set_3f_color(RED);
    set_texture(TEST);
    //draw_squaref(x, y, size);
    draw_prism_textured(x, 0, y, size, size, size);

    //draw_square_textured(this->x, this->y,this->size);
    //draw_sphere(size, x, this->size ,y);
}
