#include<stdio.h>
class Table{
public:
    int COLUMNS;
    int ROWS;
    int **array;
    Table(int columns, int rows){
        array = new *int[rows];
        for(int i = 0; i<rows;i++){
            array[i] = new int[columns];
        }
    }
    void printTable(){
        for(int i = 0; i< ROWS; i++){
            for (int j = 0; j < COLUMNS; j++){
                printf("%d",array[i][j]);
                printf("\n");
            }
        }
    }
};