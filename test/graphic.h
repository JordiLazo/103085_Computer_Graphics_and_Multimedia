using namespace std;

#define BLACK 0
#define LIGHT_GREY 1
#define DARK_GREY 2
#define RED 3
#define ORANGE 4
#define PINK 5
#define GREEN 6
#define DARK_GREEN 7
#define BLUE 8
#define COOL_BLUE 9

void draw_rectangle(int x, int y, int width, int height);
void drawSquarePixel(int x, int y, int size);
void draw_squaref(float x, float y, float size);

void setColorPixel(int color);

double scale(int input);
