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

class GenerateMap{
public:
    int columns;
    int rows;
    int **array;
    GenerateMap(int columnsMap, int rowsMap){
        this-> columns = columnsMap;
        this-> rows = rowsMap;
        array = new int*[rows];
        for(int i = 0; i<rowsMap;i++){
            array[i] = new int[columnsMap];
        }
        srand(clock());
        Position start = GenerateBaseMap();
        GenerateMapDFS(start);
        DuplicateMap();
    }
    void printTable(){
        for(int i = 0; i< rows; i++){
            for (int j = 0; j < columns; j++){
                printf("%d",array[i][j]);
            }
            printf("\n");
        }
    }
    void GenerateMapDFS(Position startPosition){
        stack<Position> stack;
        stack.push(startPosition);
        array[startPosition.y][startPosition.x] = PATH;
        while(!stack.empty()){
            Position currentPosition = stack.top();
            vector<Position> vectorVecinos = getCloseCells(currentPosition);
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
            
        }
    }

    vector<Position> getCloseCells (Position currentPosition){
        vector<Position> vectorvecinos;
        for( int i = -1; i <= 1;i++ ){
            if(i != 0){
                Position position1 = Position(2*i+ currentPosition.x,currentPosition.y);
                Position postion2 = Position(currentPosition.x,2*i+ currentPosition.y);
                if (validateCell(position1)){
                    vectorvecinos.push_back(position1);

                }
                if (validateCell(postion2)){
                    vectorvecinos.push_back(postion2);
                }
                
            }
        }
        return vectorvecinos;
    }

    bool validateCell(Position position){
        if(position.x <= 0 || position.y <= 0){
            return false;
        }
        if(position.x >= columns-1 || position.y >= rows-1){
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
        int beginColum = columns-1;
        int beginRows = rows/2;
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
        columns = columns*2;
        int *row;
        for(int i = 0; i<rows;i++){
            row = array[i];
            array[i] = new int[columns];
            for (int j = 0; j<columns/2;j++){
                array[i][j] = row[j];
                array[i][columns-1-j] = row[j];
            }
        }

    }
    
};