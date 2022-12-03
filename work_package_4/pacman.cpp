#include<GL/glut.h>
#include<iostream>
#include"map.h"
#include"player.h"
#include"food.h"
#include"enemy.h"
#include"light.h"
//-----------------------------------MAP SIZE-----------------------------------//
#define COLUMNS 10
#define ROWS 10
//-----------------------------------WINDOW SIZE-----------------------------------//
#define WIDTH 1400
#define HEIGHT 700
//-----------------------------------OPEN GL-----------------------------------//
void display();
void keyboard(int key, int x, int y);
void idle();
void specialKeyboard(unsigned char key, int x, int y);
//-----------------------------------GLOBAL FUNCTIONS-----------------------------------//
void insertEnemies();
void createMoveEnemies();
void positionObserver(float alpha,float beta,int radi);
//-----------------------------------GLOBAL VARIBALES-----------------------------------//
Map map;
Player player;
Food food;
Enemy enemy;
list<Enemy> listOfEnemies;
int pixelSize; //pixels size of each position of the map
int numberOfEnemies;
long lastTime = 0;
long currentTime;
int anglealpha=90;
int anglebeta=70;
int radiusObserver=550;
float zoom = 2;
char PATHTEXTUREFILE[] = "textures/path.jpg";
char WALLTEXTUREFILE[] = "textures/wall.jpg";
char CENTERWALLTEXTUREFILE[] = "textures/centerwall.jpg";
char BASEPATHTEXTUREFILE[] = "textures/basepath.jpg";
char ENEMYTEXTUREFILE[] = "textures/enemy.jpg";
char FOODTEXTUREFILE[] = "textures/food.jpg";
char PLAYERTEXTUREFILE[] = "textures/player.jpg";
int UP[] = {0,0,-1};
int LEFT[] = {-1,0,0};
GLint positionAmbientLight[4];
GLfloat colorAmbientLight[4];
GLfloat colorLight[4];
//-----------------------------------MAIN-----------------------------------//
int main(int argc, char *argv[]) {
//-----------------------------------SET UP GAME-----------------------------------//
    pixelSize = min(WIDTH/COLUMNS, HEIGHT/ROWS);
    numberOfEnemies = max(COLUMNS,ROWS)/5;
    map.insertMap(COLUMNS,ROWS);
    food.insertFood(pixelSize,map);
    insertEnemies();
    map.printMap();
    Position randomPositionPlayer = map.randomBasePositionPlayer();
    player.createPlayer(pixelSize, pixelSize-(COLUMNS/4), map, randomPositionPlayer);
    player.light = Light();
    player.light.color = WHITE_LIGHT;
    player.light.setDirectionCharacterLight(UP);
    player.light.setCharacterLight(player.x, pixelSize, player.y);
    positionAmbientLight[0]=0; positionAmbientLight[1]=0; positionAmbientLight[2]=0; positionAmbientLight[3]=0;
    colorAmbientLight[0]=0.95; colorAmbientLight[1]= 0.65; colorAmbientLight[2]=0.09; colorAmbientLight[3]=1.0;
    colorLight[0]=1.0; colorLight[1]=1.0; colorLight[2]=1.0; colorLight[3]=1;
//-----------------------------------OPEN GL-----------------------------------//
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Pacman Work Package 4");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutKeyboardFunc(specialKeyboard);
    glutIdleFunc(idle);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,WIDTH-1,HEIGHT-1,0);
    glBindTexture(GL_TEXTURE_2D,PATHTEXTURE);
    LoadTexture(PATHTEXTUREFILE,64);
    glBindTexture(GL_TEXTURE_2D,WALLTEXTURE);
    LoadTexture(WALLTEXTUREFILE,64);
    glBindTexture(GL_TEXTURE_2D,ENEMYTEXTURE);
    LoadTexture(ENEMYTEXTUREFILE,64);
    glBindTexture(GL_TEXTURE_2D,CENTERWALLTEXTURE);
    LoadTexture(CENTERWALLTEXTUREFILE,64);
    glBindTexture(GL_TEXTURE_2D,FOODTEXTURE);
    LoadTexture(FOODTEXTUREFILE,64);
    glBindTexture(GL_TEXTURE_2D,BASEPATHTEXTURE);
    LoadTexture(BASEPATHTEXTUREFILE,64);
    glBindTexture(GL_TEXTURE_2D,PLAYERTEXTURE);
    LoadTexture(PLAYERTEXTUREFILE,64);
    glutMainLoop();
    return 0;
}

void display(){
    glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    positionObserver(anglealpha, anglebeta, radiusObserver);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WIDTH*zoom, WIDTH*zoom, -HEIGHT*zoom, HEIGHT*zoom, 50, 1000);
    glMatrixMode(GL_MODELVIEW);
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);
    glLightiv(GL_LIGHT0,GL_POSITION,positionAmbientLight);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,colorLight);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,colorLight);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, colorAmbientLight);
    glEnable(GL_LIGHT0);
    map.drawMap(pixelSize);
    food.drawFood(pixelSize);
    enemy.drawEnemies(listOfEnemies);
    player.drawPlayer();
    player.light.illuminati();
    glutSwapBuffers();
}
//-----------------------------------PLAYER KEYBOARD-----------------------------------//
void keyboard(int key, int x, int y){
    player.handleKeyboard(key);
    glutPostRedisplay();
}
//-----------------------------------OBSERVER KEYBOARD-----------------------------------//
void specialKeyboard(unsigned char key, int x, int y){
  if (key=='w' && anglebeta<=(90-4)){
    anglebeta=(anglebeta+3);
  }else if (key=='s' && anglebeta>=(-90+4)){
    anglebeta=anglebeta-3;
  }else if (key=='a'){
    anglealpha=(anglealpha+3)%360;
  }else if (key=='d'){
    anglealpha=(anglealpha-3+360)%360;
  }else if (key=='q'){
    zoom -= 0.05;
  }else if (key=='e'){
    zoom += 0.05;
  }else if (key==27){
    exit(0);
  }
  glutPostRedisplay();
}
void positionObserver(float alpha,float beta,int radi){
  float x,y,z;
  float upx,upy,upz;
  float modul;

  x = (float)radi*cos(alpha*2*PI/360.0)*cos(beta*2*PI/360.0);
  y = (float)radi*sin(beta*2*PI/360.0);
  z = (float)radi*sin(alpha*2*PI/360.0)*cos(beta*2*PI/360.0);

  if (beta>0)
    {
      upx=-x;
      upz=-z;
      upy=(x*x+z*z)/y;
    }
  else if(beta==0)
    {
      upx=0;
      upy=1;
      upz=0;
    }
  else
    {
      upx=x;
      upz=z;
      upy=-(x*x+z*z)/y;
    }


  modul=sqrt(upx*upx+upy*upy+upz*upz);

  upx=upx/modul;
  upy=upy/modul;
  upz=upz/modul;

  gluLookAt(x,y,z,0.0, 0.0,0.0,upx,upy,upz);
}

void idle(){
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    player.createMove(currentTime-lastTime);
    player.foodCollision(&food.foodList);
    player.enemyCollision(&listOfEnemies);
    createMoveEnemies();
    lastTime = currentTime;
    glutPostRedisplay();
}
//-----------------------------------ENEMY FUNCTIONS-----------------------------------//
void insertEnemies(){
    for(int i = 0;i<numberOfEnemies;i++){
        enemy.createEnemy(pixelSize,pixelSize-14,map);
        listOfEnemies.push_back(enemy);
    }
}
void createMoveEnemies(){
    std::list<Enemy>::iterator iteratorEnemy;
    for(iteratorEnemy = listOfEnemies.begin(); iteratorEnemy != listOfEnemies.end(); ++iteratorEnemy){
        iteratorEnemy->handleKeyboard(iteratorEnemy->randomDirection());
        iteratorEnemy->createEnemyMove(currentTime-lastTime);
    }
}