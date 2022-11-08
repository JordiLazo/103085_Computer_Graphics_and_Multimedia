#include"food.h"

Food::Food(){}
Food::Food(float x, float y, float pixelSize){
    this->x = x;
    this->y = y;
    this->pixelSize = pixelSize;
}

void Food::insertFood(int pixelSize, Map map){
    float foodSize = pixelSize/2;//pixel foodSize
    float foodSizeCenter = foodSize/4;//center of the pixel foodSize
    float centerPixelSize = pixelSize/2;
    for(int i = 0; i < map.rows; i++){
        for(int j = 0; j < map.columns; j++){
            if(map.array[i][j] == PATH){
            float foodPositionJ = (j * pixelSize) + centerPixelSize - foodSizeCenter;
            float foodPositionI = (i * pixelSize) + centerPixelSize - foodSizeCenter;
            foodList.push_back(Food(foodPositionJ, foodPositionI, foodSize));
            }
        }
    }
}

void Food::drawFood(int pixelSize){
    float foodSize = pixelSize/4;
    list<Food>::iterator itemFood;
    for (itemFood = foodList.begin(); itemFood != foodList.end(); ++itemFood){
        setColorPixel("RED");
        drawCirclePixel(itemFood->x, itemFood->y, foodSize);
    }
}
/*
void Food::foodCollision(Player player) {
    std::list<Food>::iterator itemFood;
    for (itemFood = foodList.begin(); itemFood != foodList.end(); ++itemFood){
        Position obj1 = Position(player.x, player.y);
        Position obj2 = Position(itemFood->x, itemFood->y);
        if(checkFoodCollision(obj1, obj2)) {
            itemFood = foodList.erase(itemFood);
        }
    }
}
bool Food::checkFoodCollision(Position object1, Position object2){
    float dist = pixelSize/2;
    float dx = abs(object1.x - object2.x);
    float dy = abs(object1.y - object2.y);
    return dx + dy <= dist;
}
*/