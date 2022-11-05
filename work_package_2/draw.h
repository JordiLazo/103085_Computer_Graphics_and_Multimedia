#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

#define BLACK "BLACK"
#define WHITE "WHITE"
#define RED "RED"
#define BLUE "BLUE"
#define PI 3.14

void drawSquarePixel(int x, int y, int size);
void setColorPixel(string color);
void drawCirclePixel(float x, float y, float radius);