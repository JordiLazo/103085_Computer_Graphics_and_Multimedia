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
        Food(float j, float i, float pixels);
        void draw();
        float j;
        float i;
        float pixels;
        bool operator == (const Food& food) const { 
            return j == food.j && i == food.i && pixels==food.pixels;
        }
        bool operator != (const Food& food) const { return !operator==(food); }
};
