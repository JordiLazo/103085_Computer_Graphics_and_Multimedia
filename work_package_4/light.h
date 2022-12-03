#ifndef LIGHT_H
#define LIGHT_H

using namespace std;

#define RED_LIGHT 0
#define BLUE_LIGHT 1
#define WHITE_LIGHT 2
#define AMBIENT_LIGHT 3

#define FULVOUS_MATERIAL -1
#define RED_CRAYOLA_MATERIAL -2
#define DARK_GREEN_MATERIAL -3

void set_lighting_color(int light_id, int parameter, int color);
void set_light_position(int light_id, int x, int y, int z);

class Light {
    public:
    Light();
    int lightX;
    int lightY;
    int lightZ;
    int x;
    int y;
    int z;    
    int color;
    int light_id;
    void illuminati();
    void setPlayerLight(int x, int y, int z);
    void setDirectionPlayerLight(int array[]);
};
#endif