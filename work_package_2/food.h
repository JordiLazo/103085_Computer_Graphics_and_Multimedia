#include<stdio.h>
#include<stack>
#include<typeinfo>
#include<iostream>
#include<vector>


using namespace std;
#define WALL 0
#define PATH 1
#define CENTERWALL 2

class Food{
    public:
        Food(float x, float y, float pixels);
        void setPosition(int x,int y);
        void draw();
        float x;
        float y;
        float pixels;
};
