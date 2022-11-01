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
        Position start = generateBaseMap();
        generateMapDFS(start);
        createNewPaths();
        duplicateMap();
    }
    void printTable(){
        for(int i = 0; i< rows; i++){
            for (int j = 0; j < columns; j++){
                printf("%d",array[i][j]);
            }
            printf("\n");
        }
    }
    void generateMapDFS(Position startPosition){
        stack<Position> stack;
        stack.push(startPosition);
        array[startPosition.y][startPosition.x] = PATH;
        while(!stack.empty()){
            Position currentPosition = stack.top();
            vector<Position> neighborsVector = neighborsToJump(currentPosition);
            if(neighborsVector.size()== 0){
                stack.pop();
            }else{
                int choice = rand()%neighborsVector.size();
                Position randomPosition = neighborsVector[choice];
                array[randomPosition.y][randomPosition.x] = PATH;
                Position middlePos = middlePosition(currentPosition,randomPosition);
                array[middlePos.y][middlePos.x] = PATH;
                stack.push(randomPosition);

            }
            
        }
    }

    vector<Position> neighborsToJump (Position currentPosition){
        vector<Position> jumpVector;
        for( int i = -1; i <= 1;i++ ){
            if(i != 0){
                Position position1 = Position(2*i+ currentPosition.x,currentPosition.y);
                Position postion2 = Position(currentPosition.x,2*i+ currentPosition.y);
                if (validateCell(position1,false)){
                    jumpVector.push_back(position1);

                }
                if (validateCell(postion2,false)){
                    jumpVector.push_back(postion2);
                }
                
            }
        }
        return jumpVector;
    }

    bool validateCell(Position position, bool ignoreCellVisited){
        if(position.x <= 0 || position.y <= 0){
            return false;
        }
        if(position.x >= columns-1 || position.y >= rows-1){
            return false;
        }
        if(!ignoreCellVisited && array[position.y][position.x] == PATH){
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

    Position generateBaseMap(){
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
    void duplicateMap(){
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
    void createNewPaths(){
        vector<Position> possiblePathsVector;
        vector<Position> positionsToBreak;
        for(int i = 1; i< rows-2; i++){
            for (int j = 1; j < columns-2; j++){
                if(array[i][j] == PATH){
                    possiblePathsVector = getAdjacentCells(Position(j,i));
                    if(countPossiblePaths(possiblePathsVector) < 2){
                        possiblePathsVector = positionsToJump(Position(j,i));
                        Position newPos = jumpRandomCell(possiblePathsVector,Position(j,i));
                        positionsToBreak.push_back(newPos);
                    }
                }
            }
        }
        int vectorSize = positionsToBreak.size();
        for(int i = 0; i < vectorSize; i++){
            Position destroyPosition = positionsToBreak[i];
            array[destroyPosition.y][destroyPosition.x] = PATH;
        }
    }

    vector<Position> getAdjacentCells (Position currentPosition){
        vector<Position> neighborsVector;
        for( int i = -1; i <= 1;i++ ){
            if(i != 0){
                Position position1 = Position(i+ currentPosition.x,currentPosition.y);
                Position position2 = Position(currentPosition.x,i+ currentPosition.y);
                if (validateCell(position1,true)){
                    neighborsVector.push_back(position1);

                }
                if (validateCell(position2,true)){
                    neighborsVector.push_back(position2);
                }
                
            }
        }
        return neighborsVector;
    }

    vector<Position> positionsToJump (Position currentPosition){
        vector<Position> jumpVector;
        for( int i = -1; i <= 1;i++ ){
            if(i != 0){
                Position position1 = Position(2*i+ currentPosition.x,currentPosition.y);
                Position postion2 = Position(currentPosition.x,2*i+ currentPosition.y);
                if (validateCell(position1,true)){
                    jumpVector.push_back(position1);

                }
                if (validateCell(postion2,true)){
                    jumpVector.push_back(postion2);
                }
                
            }
        }
        return jumpVector;
    }

    int countPossiblePaths(vector<Position> vector){
        int counter = 0;
        int vectorSize = (int)vector.size();
        for(int i = 0; i<vectorSize; i++){
            if(array[vector[i].y][vector[i].x]== PATH){
                counter++;
            }
        }
        return counter;
    }

    Position jumpRandomCell(vector<Position> vectorClosedPaths,Position position){
        vector<Position> vectorvecinos;
        int vectorSize = (int)vectorClosedPaths.size();
        for(int i = 0; i<vectorSize; i++){
            if(array[vectorClosedPaths[i].y][vectorClosedPaths[i].x]== PATH){
                Position middlePos = middlePosition(position,vectorClosedPaths[i]);
                if(array[middlePos.y][middlePos.x] != PATH && array[middlePos.y][middlePos.x] != CENTERWALL){
                    vectorvecinos.push_back(middlePos);
                }
            }
        }
        if(vectorvecinos.size()!= 0){
            int choice = rand()%vectorvecinos.size();
            Position newPath = vectorvecinos[choice];
            return newPath;
        }
        return Position(-1,0);
    }
};