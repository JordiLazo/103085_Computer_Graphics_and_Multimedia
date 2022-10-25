#include<stdio.h>
#include<stack>
#include<typeinfo>
#include<iostream>
#include<vector>

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
        srand(clock());
        Position start = GenerateBaseMap();
        GenerateTableDFS(start);
        DuplicateMap();
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
        while(!stack.empty()){
            Position currentPosition = stack.top();
            vector<Position> vectorVecinos = getVecinos(currentPosition);
            if(vectorVecinos.size()== 0){
                stack.pop();
            }else{
                int choice = rand()%vectorVecinos.size();
                Position randomPosition = vectorVecinos[choice];
                array[randomPosition.y][randomPosition.x] = PATH;
                Position middlePos = middlePosition(currentPosition,randomPosition);
                array[middlePos.y][middlePos.x] = PATH;
                stack.push(randomPosition);

            }
            
        //     //if not vecinos pop

        }
    }
    void printStack(stack<Position> stack){
        while (!stack.empty()){
        
            stack.pop();
        }
    }

    vector<Position> getVecinos (Position currentPosition){
        vector<Position> vectorvecinos;
        for( int i = -1; i <= 1;i++ ){
            if(i != 0){
                Position position1 = Position(2*i+ currentPosition.x,currentPosition.y);
                Position postion2 = Position(currentPosition.x,2*i+ currentPosition.y);
                if (validateVecinos(position1)){
                    vectorvecinos.push_back(position1);

                }
                if (validateVecinos(postion2)){
                    vectorvecinos.push_back(postion2);
                }
                
            }
        }
        return vectorvecinos;
    }

    bool validateVecinos(Position position){
        if(position.x <= 0 || position.y <= 0){
            return false;
        }
        if(position.x >= COLUMNS-1 || position.y >= ROWS-1){
            return false;
        }if(array[position.y][position.x] == PATH){
            return false;
        }if(array[position.y][position.x] == CENTERWALL){
            return false;
        }
        return true;
    }
    Position middlePosition(Position sourcePosition, Position destinationPosition){
        int x = (destinationPosition.x + sourcePosition.x) /2 ;
        int y = (destinationPosition.y + sourcePosition.y) /2 ;
        return Position(x,y);
    }

    Position GenerateBaseMap(){
        int beginColum = COLUMNS-1;
        int beginRows = ROWS/2;
        for(int i = beginRows-3; i<= beginRows+3; i++){
            for (int j = beginColum ; j >= beginColum-4; j--){
                if(i== beginRows-3 || i==beginRows+3){
                array[i][j] = CENTERWALL;
                }else{
                  array[i][j] = PATH;  
                }
            }
            array[i][beginColum-4] = CENTERWALL;
        }
        array[beginRows-3][beginColum] = PATH;

        return Position(beginColum,beginRows-4);
    }
    void DuplicateMap(){
        COLUMNS = COLUMNS*2;
        int *row;
        for(int i = 0; i<ROWS;i++){
            row = array[i];
            array[i] = new int[COLUMNS];
            for (int j = 0; j<COLUMNS/2;j++){
                array[i][j] = row[j];
                array[i][COLUMNS-1-j] = row[j];
            }
        }

    }
    
};