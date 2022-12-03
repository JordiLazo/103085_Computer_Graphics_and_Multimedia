#include"draw.h"

int offset = 0;
int raised = 0;
int color;
int texture;

//-----------------------------------DRAW FUNCTIONS-----------------------------------//

void drawTextured2dRectangle(int x, int y, int width, int height){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture);
    glBegin(GL_QUADS);
    glNormal3f(0,-1,0);
    glTexCoord2f(0.0,1.0); glVertex3i(x+offset,0+raised,y+offset);
    glNormal3f(0,-1,0);
    glTexCoord2f(0.0,0.0); glVertex3i(x+offset,0+raised,y+height+offset);
    glNormal3f(0,-1,0);
    glTexCoord2f(1.0,0.0); glVertex3i(x+width+offset, 0+raised, y+height+offset);
    glNormal3f(0,-1,0);
    glTexCoord2f(1.0,1.0); glVertex3i(x+width+offset, 0+raised,y+offset);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void drawTextured3dRectangle(int x, int y, int z, int width, int height, int length){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture);

    glBegin(GL_QUADS);
    setHeight(height);
    glNormal3f(0,1,0);
    glTexCoord2f(0.0,1.0); glVertex3i(offset+x, raised+y, offset+z+length);
    glTexCoord2f(0.0,0.0); glVertex3i(offset+x+width, raised+y, offset+z+length);
    glTexCoord2f(1.0,0.0); glVertex3i(offset+x+width, raised+y, offset+z);
    glTexCoord2f(1.0,1.0);glVertex3i(offset+x, raised+y, offset+z);
    glEnd();

    glBegin(GL_QUADS);
    setHeight(0);
    glNormal3f(1,0,0);
    glTexCoord2f(0.0,1.0); glVertex3i(offset+x+width, raised+y+height, offset+z);
    glTexCoord2f(0.0,0.0); glVertex3i(offset+x+width, raised+y+height, offset+z+length);
    glTexCoord2f(1.0,0.0); glVertex3i(offset+x+width, raised+y, offset+z+length);
    glTexCoord2f(1.0,1.0); glVertex3i(offset+x+width, raised+y, offset+z);
    glEnd();

    glBegin(GL_QUADS);
    setHeight(0);
    glNormal3f(0,0,1);
    glTexCoord2f(0.0,1.0); glVertex3i(offset+x+width, raised+y, offset+z+length);
    glTexCoord2f(0.0,0.0); glVertex3i(offset+x+width, raised+y+height, offset+z+length);
    glTexCoord2f(1.0,0.0); glVertex3i(offset+x, raised+y+height, offset+z+length);
    glTexCoord2f(1.0,1.0); glVertex3i(offset+x, raised+y, offset+z+length);
    glEnd();

    glBegin(GL_QUADS);
    setHeight(0);
    glNormal3f(-1,0,0);
    glTexCoord2f(0.0,1.0); glVertex3i(offset+x, raised+y, offset+z+length);
    glTexCoord2f(0.0,0.0); glVertex3i(offset+x, raised+y+height, offset+z+length);
    glTexCoord2f(1.0,0.0); glVertex3i(offset+x, raised+y+height, offset+z);
    glTexCoord2f(1.0,1.0); glVertex3i(offset+x, raised+y, offset+z);
    glEnd();

    glBegin(GL_QUADS);
    setHeight(0);
    glNormal3f(0,0,-1);
    glTexCoord2f(0.0,1.0); glVertex3i(offset+x, raised+y, offset+z);
    glTexCoord2f(0.0,0.0); glVertex3i(offset+x, raised+y+height, offset+z);
    glTexCoord2f(1.0,0.0); glVertex3i(offset+x+width, raised+y+height, offset+z);
    glTexCoord2f(1.0,1.0); glVertex3i(offset+x+width, raised+y, offset+z);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void draw3dRectangle(int x, int y, int z, int width, int height, int length){
    setColorPixel(BLACK);
    glNormal3f(0,1,0);
    glBegin(GL_QUADS);
    setHeight(height);
    glVertex3i(offset+x, raised+y, offset+z+length);
    glVertex3i(offset+x+width, raised+y, offset+z+length);
    glVertex3i(offset+x+width, raised+y, offset+z);
    glVertex3i(offset+x, raised+y, offset+z);
    glEnd();

    glNormal3f(1,0,0);
    setColorPixel(BLACK);
    glBegin(GL_QUADS);
    setHeight(0);
    glVertex3i(offset+x+width, raised+y+height, offset+z);
    glVertex3i(offset+x+width, raised+y+height, offset+z+length);
    glVertex3i(offset+x+width, raised+y, offset+z+length);
    glVertex3i(offset+x+width, raised+y, offset+z);
    glEnd();

    glNormal3f(0,0,1);
    setColorPixel(BLACK);
    glBegin(GL_QUADS);
    setHeight(0);
    glVertex3i(offset+x+width, raised+y, offset+z+length);
    glVertex3i(offset+x+width, raised+y+height, offset+z+length);
    glVertex3i(offset+x, raised+y+height, offset+z+length);
    glVertex3i(offset+x, raised+y, offset+z+length);
    glEnd();

    glNormal3f(-1,0,0);
    setColorPixel(BLACK);
    glBegin(GL_QUADS);
    setHeight(0);
    glVertex3i(offset+x, raised+y, offset+z+length);
    glVertex3i(offset+x, raised+y+height, offset+z+length);
    glVertex3i(offset+x, raised+y+height, offset+z);
    glVertex3i(offset+x, raised+y, offset+z);
    glEnd();

    glNormal3f(0,0,-1);
    setColorPixel(BLACK);
    glBegin(GL_QUADS);
    setHeight(0);
    glVertex3i(offset+x, raised+y, offset+z);
    glVertex3i(offset+x, raised+y+height, offset+z);
    glVertex3i(offset+x+width, raised+y+height, offset+z);
    glVertex3i(offset+x+width, raised+y, offset+z);
    glEnd();
}
void draw3dSphere(int radius, int x, int y, int z){
    glPushMatrix();
        glTranslatef(x+offset,y,z+offset);
        glutSolidSphere(radius, 20, 20);
    glPopMatrix();
}
void setOffset(int newOffset){
    offset = newOffset;
}
void setHeight(int newHeight){
    raised = newHeight;
}
void setTexture(int newTexture){
    texture = newTexture;
}

void setColorPixel(string color){
    if(color == "BLACK"){
        glColor3f(0,0,0);
    }
    if(color == "WHITE"){
        glColor3f(255,255,255);
    }
    if(color == "RED"){
        glColor3f(255,0,0);
    }
    if(color == "BLUE"){
        glColor3f(0,0,255);
    }
    if(color == "YELLOW"){
        glColor3f(255,255,0);
    }
    if(color == "GREEN"){
        glColor3f(0,255,0);
    }
    if(color == "ORANGE"){
        glColor3f(1.0f, 0.5f, 0.0f);
    }
    if(color == "SKYBLUE"){
        glColor3f(0.0f, 0.5f, 0.5f);
    }
}
//-----------------------------------TEXTURES FUNCTIONS-----------------------------------//
void ReadJPEG(char *filename,unsigned char **image,int *width, int *height)
{
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;
  FILE * infile;
  unsigned char **buffer;
  int i,j;

  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_decompress(&cinfo);


  if ((infile = fopen(filename, "rb")) == NULL) {
    printf("Unable to open file %s\n",filename);
    exit(1);
  }

  jpeg_stdio_src(&cinfo, infile);
  jpeg_read_header(&cinfo, TRUE);
  jpeg_calc_output_dimensions(&cinfo);
  jpeg_start_decompress(&cinfo);

  *width = cinfo.output_width;
  *height  = cinfo.output_height;


  *image=(unsigned char*)malloc(cinfo.output_width*cinfo.output_height*cinfo.output_components);

  buffer=(unsigned char **)malloc(1*sizeof(unsigned char **));
  buffer[0]=(unsigned char *)malloc(cinfo.output_width*cinfo.output_components);


  i=0;
  while (cinfo.output_scanline < cinfo.output_height) {
    jpeg_read_scanlines(&cinfo, buffer, 1);

    for(j=0;j<(int)cinfo.output_width*cinfo.output_components;j++)
      {
	(*image)[i]=buffer[0][j];
	i++;
      }

    }

  free(buffer);
  jpeg_finish_decompress(&cinfo);
}

void LoadTexture(char *filename,int dim)
{
  unsigned char *buffer;
  unsigned char *buffer2;
  int width,height;
  long i,j;
  long k,h;

  ReadJPEG(filename,&buffer,&width,&height);

  buffer2=(unsigned char*)malloc(dim*dim*3);

  //-- The texture pattern is subsampled so that its dimensions become dim x dim --
  for(i=0;i<dim;i++)
    for(j=0;j<dim;j++)
      {
	k=i*height/dim;
	h=j*width/dim;

	buffer2[3*(i*dim+j)]=buffer[3*(k*width +h)];
	buffer2[3*(i*dim+j)+1]=buffer[3*(k*width +h)+1];
	buffer2[3*(i*dim+j)+2]=buffer[3*(k*width +h)+2];

      }

  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,dim,dim,0,GL_RGB,GL_UNSIGNED_BYTE,buffer2);

  free(buffer);
  free(buffer2);
}
