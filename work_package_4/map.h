#include<stdio.h>
#include<stack>
#include<typeinfo>
#include<iostream>
#include<vector>
#include<list>
#include"draw.h"
#include"position.h"

using namespace std;
#define WALL 0
#define PATH 1
#define CENTERWALL 2
#define BASEPATH 3

#ifndef MAP
#define MAP

class Map{
public:
//-----ATTRIBUTES-----//
    int columns;
    int rows;
    int **array;
    int pixelSize;
    Position positionExitBasePostion;
//-----FUNCTIONS-----//
    Map();
    Map(int columnsMap, int rowsMap);
    Position randomBasePositionEnemy();
    Position randomBasePositionPlayer();
    Position exitBasePostion();
//-------DRAW MAP-------//
    void drawMap(int pixelSize);
    void printMap();
//-------GENERATE MAP-------//
    void insertMap(int columnsMap, int rowsMap);
    bool validateCell(Position position, bool ignoreCellVisited);
    void generateMapDFS(Position startPosition);
    void duplicateMap();
    void createNewPaths();
    int countPossiblePaths(vector<Position> vector);
    vector<Position> neighborsToJump (Position currentPosition);
    Position middlePosition(Position sourcePosition, Position destinationPosition);
    Position generateBaseMap();
    vector<Position> getAdjacentCells (Position currentPosition);
    vector<Position> positionsToJump (Position currentPosition);
    Position jumpRandomCell(vector<Position> vectorClosedPaths,Position position);
};
#endif