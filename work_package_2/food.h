#include<list>
#include"map.h"
#include"player.h"

#ifndef FOOD
#define FOOD

class Food{
    public:
        Food(float x, float y, float pixelSize);
        Food();
        float x;
        float y;
        float pixelSize;
        list<Food> foodList;
        Map map;
        bool checkFoodCollision(Position object1, Position object2);
        void foodCollision(Player player);
        void insertFood(int pixelSize, Map map);
        void drawFood(int pixelSize);
        //----COMPARATOR---//
        bool operator == (const Food& food) const { 
            return x == food.x && y == food.y && pixelSize==food.pixelSize;
        }
        bool operator != (const Food& food) const { return !operator==(food); }
};
#endif