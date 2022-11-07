#include"food.h"

Food::Food(float x, float y, float pixelSize){
    this->x = x;
    this->y = y;
    this->pixelSize = pixelSize;
};
/*
void Food::insertFood(int pixelSize, Map map){
    float foodSize = pixelSize/4;//pixel foodSize
    float foodSizeCenter = foodSize/2;//center of the pixel foodSize
    float centerPixelSize = pixelSize/2;
    for(int i = 0; i < map.rows; i++){
        for(int j = 0; j < map.columns; j++){
            if(map.array[i][j] == PATH){
            // calculate position of food inside the pixel
            float foodPositionJ = (j * pixelSize) + centerPixelSize - foodSizeCenter;
            float foodPositionI = (i * pixelSize) + centerPixelSize - foodSizeCenter;
            foodList.push_back(Food(foodPositionJ, foodPositionI, foodSize));
            }
        }
    }
}

void Food::drawFood(int pixelSize){
    float foodSize = pixelSize/3;
    list<Food>::iterator itemFood;
    for (itemFood = foodList.begin(); itemFood != foodList.end(); ++itemFood){
        setColorPixel("RED");
        drawSquarePixel(itemFood->x, itemFood->y, foodSize);
    }
    //printf("My size:%d\n", foodList.size());
}

void Food::foodCollision(Player player) {
    std::list<Food>::iterator food;
    for (food = foodList.begin(); food != foodList.end(); ++food){
        Position obj1 = Position(player.x, player.y);
        Position obj2 = Position(food->x, food->y);
        if(checkFoodCollision(obj1, obj2)) {
            food = map.foodList.erase(food);
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