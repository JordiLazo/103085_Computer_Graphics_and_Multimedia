#define GRASS 0
#define COBBLESTONE 1
#define TEST 2

void ReadJPEG(char *filename,unsigned char **image,int *width, int *height);
void LoadTexture(char *filename,int dim);

void set_texture(int new_texture);