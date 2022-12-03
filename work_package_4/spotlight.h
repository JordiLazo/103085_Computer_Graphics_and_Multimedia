#ifndef LIGHT_H
#define LIGHT_H

class Light {
    public:
    Light();
    int lightX;
    int lightY;
    int lightZ;
    int x;
    int y;
    int z;
    void illuminati();
    void setCharacterLight(int x, int y, int z);
    void setDirectionCharacterLight(int array[]);
    void createLight(int x, int y, int z);
    void directionLight(int x, int y, int z);
};
#endif