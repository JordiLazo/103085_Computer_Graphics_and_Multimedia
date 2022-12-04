#ifndef SPOTLIGHT
#define SPOTLIGHT

class Spotlight {
    public:
    Spotlight();
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