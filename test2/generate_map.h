#include <time.h>
#include <stack>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
class Cell {       
  public:             
    int row;        
    int column;
    int value;
    int blocked=0;
    Cell();
    Cell(int x, int y, int z){
    	row=x;
    	column=y;
    	value=z;
    
    }  
};
Cell::Cell(){};
Cell** dfs_genempty(int HEIGHT, int WEIGHT); 

using namespace std;

Cell** dfs_generation(int HEIGHT, int WEIGHT){
    Cell **map;
	Cell **mapBig;
    srand (time(NULL));
    map=new Cell*[HEIGHT];
	
	for (int i=0; i<HEIGHT; i++){
		map[i]=new Cell[WEIGHT];
	}
	stack<Cell> stack;
    int halfHeight= HEIGHT/2;
    int randNum=0;
	int row, column=0;
	for(row=0; row<HEIGHT; row++){
		for(column=0; column<WEIGHT; column++){
			if(row==0 || column==0 || row== HEIGHT-1 || column==WEIGHT-1){
				map[row][column]=Cell(row,column,2);
			}

			else{
				map[row][column]=Cell(row,column,0);
                if(row==1){
                    map[row][column].blocked++;
                }
                if(column==1){
                    map[row][column].blocked++;
                }
                if(row==HEIGHT-2){
                    map[row][column].blocked++;
                }
                if(column==WEIGHT-2){
                    map[row][column].blocked++;
                }
			}
			
			printf("%d ",map[row][column].value);
			}
		printf("\n");
    }

    map[halfHeight][WEIGHT-2].value=3;
    map[halfHeight][WEIGHT-3].value=3;
    map[halfHeight][WEIGHT-4].value=3;
    map[halfHeight][WEIGHT-5].value=3;
    map[halfHeight+1][WEIGHT-5].value=3;
    map[halfHeight+2][WEIGHT-5].value=3;
    map[halfHeight+3][WEIGHT-5].value=3;
    map[halfHeight+4][WEIGHT-5].value=3;
    map[halfHeight+4][WEIGHT-4].value=3;
    map[halfHeight+4][WEIGHT-3].value=3;
    map[halfHeight+4][WEIGHT-2].value=3;



	map[HEIGHT-2][WEIGHT-2].value=1;
	stack.push(map[1][1]);
	while(!stack.empty()){
		Cell current=stack.top();
		randNum= 0+(rand()%4);
		if(randNum==0 && (current.column+1<WEIGHT && map[current.row][current.column+1].value==0)){//Moure dreta
		
				map[current.row][current.column+1].value=1;
				if(current.row-1>0 && map[current.row-1][current.column+1].value==0 && map[current.row][current.column].blocked<2){
					map[current.row-1][current.column].value=2;
                    map[current.row][current.column].blocked++;
				}
				if(current.row+1<HEIGHT && map[current.row+1][current.column].value==0 && map[current.row][current.column].blocked<2){
					map[current.row+1][current.column].value=2;
                    map[current.row][current.column].blocked++;
				}
				stack.push(map[current.row][current.column+1]);
				
				
		}
		
		else if(randNum==1 && (current.column-1>0 && map[current.row][current.column-1].value==0)){//Moure esquerra
			
				map[current.row][current.column-1].value=1;
				if(current.row-1>0 && map[current.row-1][current.column].value==0 && map[current.row][current.column].blocked<2){
					map[current.row-1][current.column].value=2;
                    map[current.row][current.column].blocked++;
				}
				if(current.row+1<HEIGHT && map[current.row+1][current.column].value==0 && map[current.row][current.column].blocked<2){
					map[current.row+1][current.column].value=2;
                    map[current.row][current.column].blocked++;
				}
				stack.push(map[current.row][current.column-1]);
				
				
			
		}
		else if(randNum==2 && (current.row+1<HEIGHT && map[current.row+1][current.column].value==0)){//Moure abaix
			
				map[current.row+1][current.column].value=1;
				if(current.column-1>0 && map[current.row][current.column-1].value==0 && map[current.row][current.column].blocked<2){
					map[current.row][current.column-1].value=2;
                    map[current.row][current.column].blocked++;
				}
				if(current.column+1<WEIGHT && map[current.row][current.column+1].value==0 && map[current.row][current.column].blocked<2){
					map[current.row][current.column+1].value=2;
                    map[current.row][current.column].blocked++;
				}
				stack.push(map[current.row+1][current.column]);
				
				
			
		}
		else if(randNum==3 && (current.row-1>0 && map[current.row-1][current.column].value==0)){//Moure adalt
		
				map[current.row-1][current.column].value=1;
				if(current.column-1>0 && map[current.row][current.column-1].value==0 && map[current.row][current.column].blocked<2){
					map[current.row][current.column-1].value=2;
                    map[current.row][current.column].blocked++;
				}
				if(current.column+1<WEIGHT && map[current.row][current.column+1].value==0 && map[current.row][current.column].blocked<2){
					map[current.row][current.column+1].value=2;
                    map[current.row][current.column].blocked++;
				}
				stack.push(map[current.row-1][current.column]);
				
				
			
		}

        
		
		//Backtracking until dead!!!
		
		
		else if(!(map[current.row-1][current.column].value==0 )&& !(map[current.row+1][current.column].value==0) && !(map[current.row][current.column-1].value==0) && !(map[current.row][current.column+1].value==0)){
            stack.pop();
		}
		
	}

	mapBig=	dfs_genempty(HEIGHT, 2*WEIGHT);

	for(row=0; row<HEIGHT; row++){
		for(column=0; column<2*WEIGHT; column++){
			if(column<WEIGHT){
				mapBig[row][column]=map[row][column];
				mapBig[row][2*WEIGHT-column-1]=mapBig[row][column];
				}
			else	
			mapBig[row][2*WEIGHT-column-1]=mapBig[row][column];
			
			printf("%d ",mapBig[row][column].value);
			}
		printf("\n");
    }



	
    //map=clear_map(map);
    return mapBig;

}

Cell** dfs_genempty(int HEIGHT, int WEIGHT){
	Cell **map;
    srand (time(NULL));
    map=new Cell*[HEIGHT];
	
	for (int i=0; i<HEIGHT; i++){
		map[i]=new Cell[WEIGHT];
	}
	stack<Cell> stack;
    int halfHeight= HEIGHT/2;
    int randNum=0;
	int row, column=0;

	for(row=0; row<HEIGHT; row++){
		for(column=0; column<WEIGHT; column++){
			if(row==0 || column==0 || row== HEIGHT-1 || column==WEIGHT-1){
				map[row][column]=Cell(row,column,2);
			}

			else{
				map[row][column]=Cell(row,column,0);
                if(row==1){
                    map[row][column].blocked++;
                }
                if(column==1){
                    map[row][column].blocked++;
                }
                if(row==HEIGHT-2){
                    map[row][column].blocked++;
                }
                if(column==WEIGHT-2){
                    map[row][column].blocked++;
                }
			}
			
			}
		
    }

    map[halfHeight][WEIGHT-2].value=3;
    map[halfHeight][WEIGHT-3].value=3;
    map[halfHeight][WEIGHT-4].value=3;
    map[halfHeight][WEIGHT-5].value=3;
    map[halfHeight+1][WEIGHT-5].value=3;
    map[halfHeight+2][WEIGHT-5].value=3;
    map[halfHeight+3][WEIGHT-5].value=3;
    map[halfHeight+4][WEIGHT-5].value=3;
    map[halfHeight+4][WEIGHT-4].value=3;
    map[halfHeight+4][WEIGHT-3].value=3;
    map[halfHeight+4][WEIGHT-2].value=3;



	map[HEIGHT-2][WEIGHT-2].value=1;
	//map=clear_map(map);
    return map;

}