#include<GL/glut.h>
#include"class.h"

#define COLUMNS 8
#define ROWS 8
#define WIDTH 300
#define HEIGHT 300

int main(){
    Table table(COLUMNS,ROWS);
    table.printTable();
}
