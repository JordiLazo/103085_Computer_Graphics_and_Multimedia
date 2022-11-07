#ifndef FOOD
#define FOOD

class Food{
    public:
        Food(float x, float y, float pixelSize);
        float x;
        float y;
        float pixelSize;
        bool operator == (const Food& food) const { 
            return x == food.x && y == food.y && pixelSize==food.pixelSize;
        }
        bool operator != (const Food& food) const { return !operator==(food); }
};
#endif