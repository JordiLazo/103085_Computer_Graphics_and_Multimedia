#include<GL/glut.h>
#include<iostream>
#include<vector>
#include"draw.h"

void drawVector(int width, int height,GenerateMap map){
    for(int i = 0; i < map.rows; i++){
        for(int j = 0; j < map.columns; j++){
            if(map.array[i][j] == PATH){
                glColor3f(0.8,0.8,0.8);
                glBegin(GL_QUADS);
                glVertex2i(j*width/map.columns,i*height/map.rows);
                glVertex2i((j+1)*width/map.columns,i*height/map.rows); 
                glVertex2i((j+1)*width/map.columns,(i+1)*height/map.rows); 
                glVertex2i(j*width/map.columns,(i+1)*height/map.rows); 
                glEnd();
            }
        }
    }
}