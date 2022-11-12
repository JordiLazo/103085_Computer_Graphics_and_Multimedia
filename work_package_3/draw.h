#include<GL/glut.h>
#include<iostream>
#include<cmath>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"jpeglib.h"
using namespace std;

#define BLACK "BLACK"
#define WHITE "WHITE"
#define RED "RED"
#define BLUE "BLUE"
#define YELLOW "YELLOW"
#define ORANGE "ORANGE"
#define SKYBLUE "SKYBLUE"
#define PATHTEXTURE 0
#define WALLTEXTURE 1
#define CENTERWALLTEXTURE 2
#define BASEPATHTEXTURE 3
#define ENEMYTEXTURE 4
#define PLAYERTEXTURE 5
#define FOODTEXTURE 6
#define PI 3.14

#ifndef DRAW
#define DRAW

void drawSquarePixel(int x, int y, int size);
void drawCube(int size, int x, int y, int z);
void setColorPixel(string color);
void drawCirclePixel(float x, float y, float radius);
void drawCirclePixel3D(int radius, int x, int y, int z);
void set_offset(int new_offset);
void draw_prism_textured(int x, int y, int z, int width, int height, int length);
void draw_rectangle_textured(int x, int y, int width, int height);
void ReadJPEG(char *filename,unsigned char **image,int *width, int *height);
void LoadTexture(char *filename,int dim);
void set_texture(int new_texture);
void set_raised(int new_raised);
#endif