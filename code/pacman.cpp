#include<GL/glut.h>
#include<iostream>
#include"map.h"

#define COLUMNS 8
#define ROWS 8
#define WIDTH 300
#define HEIGHT 300s

int main(){
    Table table(COLUMNS,ROWS);
    table.printTable();
}
