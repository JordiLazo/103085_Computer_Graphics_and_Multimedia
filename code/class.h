#include<stdio.h>
#include<stack>
using namespace std;
#define WALL 0
#define PATH 1
#define CENTERWALL 2

class Position{
    public:
    int x;
    int y;
    Position(int x, int y){
        this-> x = x;
        this-> y = y;
    }
};

class Table{
public:
    int COLUMNS;
    int ROWS;
    int **array;
    Table(int columns, int rows){
        COLUMNS = columns;
        ROWS = rows;
        array = new int*[rows];
        for(int i = 0; i<rows;i++){
            array[i] = new int[columns];
        }
        GenerateTableDFS(Position(columns/2,rows/2));
    }
    void printTable(){
        for(int i = 0; i< ROWS; i++){
            for (int j = 0; j < COLUMNS; j++){
                printf("%d",array[i][j]);
            }
            printf("\n");
        }
    }
    void GenerateTableDFS(Position startPosition){
        stack<Position> pila;
        pila.push(startPosition);
        array[startPosition.y][startPosition.x] = PATH;
        while(!pila.empty()){
            Position currentPosition = pila.top();
            //buscar vecinos
            //push vecino 1
            //if not vecinos pop

        }
    }
};