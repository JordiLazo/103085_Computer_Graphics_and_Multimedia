#include<stdio.h>
#include<stack>
#include<typeinfo>
#include<iostream>
#include<vector>
#include<list>
#include"draw.h"
#include"food.h"
#include"position.h"

using namespace std;
#define WALL 0
#define PATH 1
#define CENTERWALL 2


#ifndef MAP
#define MAP

class Map{
public:
//-----ATTRIBUTES-----//
    int columns;
    int rows;
    int **array;
    int pixelSize;
    list<Food> foodList;
//-----FUNCTIONS-----//
    Map();
    Map(int columnsMap, int rowsMap);
    void generateMap(int columnsMap, int rowsMap);
    void drawMap(int pixelSize);
    void drawFood(int pixelSize);
    bool validateCell(Position position, bool ignoreCellVisited);
    void printMap();
    void generateMapDFS(Position startPosition);
    void duplicateMap();
    void createNewPaths();
    int countPossiblePaths(vector<Position> vector);
    Position startPosition();
    vector<Position> neighborsToJump (Position currentPosition);
    Position middlePosition(Position sourcePosition, Position destinationPosition);
    Position generateBaseMap();
    vector<Position> getAdjacentCells (Position currentPosition);
    vector<Position> positionsToJump (Position currentPosition);
    Position jumpRandomCell(vector<Position> vectorClosedPaths,Position position);
};
#endif