#include<stdio.h>
#include<stack>
#include<typeinfo>
#include<iostream>
#include<vector>

using namespace std;
#define WALL 0
#define PATH 1
#define CENTERWALL 2

class Character{
    public:
    int x;
    int y;
    Character(int x, int y){
        this-> x = x;
        this-> y = y;
    }
};

