#include"map.h"

//-------MAP CONSTRUCTOR-------//
Map::Map(int columnsMap, int rowsMap) {
    generateMap(columns,rows);
}
//-------MAP EMPTY CONSTRUCTOR-------//
Map::Map(){};

//-------DRAW FUNCTIONS-------//
void Map::drawMap(int pixelSize){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(this->array[i][j] == PATH){
                setColorPixel("WHITE");
                drawSquarePixel(j*pixelSize, i*pixelSize, pixelSize);
            }
            if(this->array[i][j] == WALL){
                setColorPixel("BLUE");
                drawSquarePixel(j*pixelSize, i*pixelSize, pixelSize);
            }
            if(this->array[i][j] == CENTERWALL){
                setColorPixel("BLACK");
                drawSquarePixel(j*pixelSize, i*pixelSize, pixelSize);
            }
        }
    }
}

void Map::drawFood(int pixelSize){
    float foodSize = pixelSize/4;
    list<Food>::iterator itemFood;
    for (itemFood = foodList.begin(); itemFood != foodList.end(); ++itemFood){
        setColorPixel("RED");
        drawCirclePixel(itemFood->x, itemFood->y, foodSize);
    }
}
void Map::insertFood(int pixelSize){
    float foodSize = pixelSize/4;//pixel foodSize
    float foodSizeCenter = foodSize/2;//center of the pixel foodSize
    float centerPixelSize = pixelSize/2;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(this->array[i][j] == PATH){
            // calculate position of food inside the pixel
            float foodPositionJ = (j * pixelSize) + centerPixelSize - foodSizeCenter;
            float foodPositionI = (i * pixelSize) + centerPixelSize - foodSizeCenter;
            foodList.push_back(Food(foodPositionJ, foodPositionI, foodSize));
            }
        }
    }
}

void Map::printMap(){
    for(int i = 0; i< rows; i++){
        for (int j = 0; j < columns; j++){
            printf("%d",array[i][j]);
        }
        printf("\n");
    }
}
//-------GENERATE MAP-------//
void Map::generateMap(int columnsMap, int rowsMap){
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
void Map::generateMapDFS(Position startPosition){
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

vector<Position> Map::neighborsToJump (Position currentPosition){
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

bool Map::validateCell(Position position, bool ignoreCellVisited){
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
Position Map::middlePosition(Position sourcePosition, Position destinationPosition){
    int x = (destinationPosition.x + sourcePosition.x) /2 ;
    int y = (destinationPosition.y + sourcePosition.y) /2 ;
    return Position(x,y);
}

Position Map::generateBaseMap(){
    int beginColum = columns-1;
    int beginRows = rows/2;
    int rowWidthCenterWall = 4;
    int rowLongCenterWall = 2;
    for(int i = beginRows-rowLongCenterWall; i<= beginRows+rowLongCenterWall; i++){
        for (int j = beginColum ; j >= beginColum-rowWidthCenterWall; j--){
            if(i== beginRows-rowLongCenterWall || i==beginRows+rowLongCenterWall){
            array[i][j] = CENTERWALL;
            }else{
                array[i][j] = PATH;  
            }
        }
        array[i][beginColum-rowWidthCenterWall] = CENTERWALL;
    }
    array[beginRows-rowLongCenterWall][beginColum] = PATH;

    return Position(beginColum,beginRows-(rowLongCenterWall+1));
}
void Map::duplicateMap(){
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
void Map::createNewPaths(){
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

vector<Position> Map::getAdjacentCells (Position currentPosition){
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

vector<Position> Map::positionsToJump (Position currentPosition){
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

int Map::countPossiblePaths(vector<Position> vector){
    int counter = 0;
    int vectorSize = (int)vector.size();
    for(int i = 0; i<vectorSize; i++){
        if(array[vector[i].y][vector[i].x]== PATH){
            counter++;
        }
    }
    return counter;
}

Position Map::jumpRandomCell(vector<Position> vectorClosedPaths,Position position){
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