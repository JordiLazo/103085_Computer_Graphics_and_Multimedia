#include"food.h"

Food::Food(){}
Food::Food(float x, float y, float pixelSize){
    this->x = x;
    this->y = y;
    this->pixelSize = pixelSize;
}

void Food::insertFood(int pixelSize, Map map){
    float foodSize = pixelSize;//pixel foodSize
    foodSize = ((int)foodSize % 2 == 0) ? foodSize +1: foodSize;
    float foodSizeCenter = foodSize/2;//center of the pixel foodSize
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
    float foodSize = pixelSize/2;
    list<Food>::iterator itemFood;
    for (itemFood = foodList.begin(); itemFood != foodList.end(); ++itemFood){
        //set_material_id(DARK_GREEN_MATERIAL);
        //draw3dRectangle(itemFood->x, 0,itemFood->y, foodSize, foodSize, foodSize);
        setTexture(FOODTEXTURE);
        drawTextured3dRectangle(itemFood->x, 0,itemFood->y, foodSize, foodSize, foodSize);
    }
}