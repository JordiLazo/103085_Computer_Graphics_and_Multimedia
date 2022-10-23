#include<stdio.h>
#include<stack>
#include<typeinfo>
#include<iostream>

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
        GenerateTableDFS(Position(columns,rows));
    }
    void printTable(){
        for(int i = 0; i< ROWS; i++){
            for (int j = 0; j < COLUMNS; j++){
                // if(i == 0 || j == ROWS-1 || j == 0 || i == ROWS-1){
                //     array[i][j] = PATH;
                // }
                printf("%d",array[i][j]);
            }
            printf("\n");
        }
    }
    void GenerateTableDFS(Position startPosition){
        stack<Position> stack;
        stack.push(startPosition);
        array[startPosition.y][startPosition.x] = PATH;
        printStack(stack);
        // while(!pila.empty()){
        //     Position currentPosition = pila.top();
        //     //buscar vecinos
        //     //push vecino 1
        //     //if not vecinos pop

        // }
    }
    void printStack(stack<Position> stack){
        while (!stack.empty()){
        
            stack.pop();
        }
        
    }
};