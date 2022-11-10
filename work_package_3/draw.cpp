#include"draw.h"

int offset = 0;
int raised = 0;
float color_offset = 0;
int saved_color;

void set_offset(int new_offset){
    offset = new_offset;
}
void drawCirclePixel3D(int radius, int x, int y, int z){
    glPushMatrix();
    glTranslatef(x+offset,y,z+offset);
    glutSolidSphere(radius, 20, 20);
    glPopMatrix();
}
void drawSquarePixel(int j, int i, int size){
    glBegin(GL_QUADS);
    glVertex3i(j+offset,0+raised,i+offset);
    glVertex3i(j+offset,0+raised,i+size+offset);
    glVertex3i(j+size+offset, 0+raised,i+size+offset);
    glVertex3i(j+size+offset,0+raised, i+offset);
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
    if(color == "ORANGE"){
        glColor3f(1.0f, 0.5f, 0.0f);
    }
    if(color == "SKYBLUE"){
        glColor3f(0.0f, 0.5f, 0.5f);
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