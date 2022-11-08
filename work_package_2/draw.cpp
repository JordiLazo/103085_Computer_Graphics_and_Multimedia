#include"draw.h"

void drawSquarePixel(int j, int i, int size){
    glBegin(GL_QUADS);
    glVertex2i(j,i);
    glVertex2i(j,i+size);
    glVertex2i(j+size, i+size);
    glVertex2i(j+size, i);
    glEnd();
}

void setColorPixel(string color){
    if(color == "BLACK"){
        glColor3f(0,0,0);
    }
    if(color == "WHITE"){
        glColor3f(255,255,255);
    }
    if(color == "RED"){
        glColor3f(255,0,0);
    }
    if(color == "BLUE"){
        glColor3f(0,0,255);
    }
    if(color == "YELLOW"){
        glColor3f(255,255,0);
    }
    if(color == "GREEN"){
        glColor3f(0,255,0);
    }
}
void drawCirclePixel(float x, float y, float radius){
	int triangleAmount = 20; //# of triangles used to draw circle
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount;i++) { 
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)), 
            y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}