#include <stdio.h>

#define R 7
#define C 8

//定义并初始化迷宫 
int M[R+2][C+2]={
				 {1,1,1,1,1,1,1,1,1,1},
				 {1,0,1,1,1,1,1,1,1,1},
				 {1,0,0,1,1,1,1,1,1,1},
				 {1,0,0,0,0,1,1,1,1,1},
				 {1,0,1,1,0,0,0,0,1,1},
				 {1,0,0,1,0,0,1,0,1,1},
				 {1,1,1,1,0,0,1,0,1,1},
				 {1,1,1,1,0,0,0,0,0,1},
				 {1,1,1,1,1,1,1,1,1,1}
				};
int t[R+2][C+2]={0};	//标志已走的路的数组 
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};	//定义移动探查的数组 
int tag=0;

int Maze (int x,int y){
	int i;
	int a=0,b=0;
	if (x==7 && y==8)
		return 1;
	for (i=0;i<4;i++){
		a=x+Move[i][0];
		b=y+Move[i][1];
		if (M[a][b]==0 && !t[a][b]){
			t[a][b]=1;	//标志已走的路
			tag=Maze(a,b);
			if (tag==1){
				printf("(%d,%d)<-",a,b);
				return 1;
			} 
		}
	}
	return 0;
} 

int main (void){
	int i, j;
	printf("原迷宫为：\n");
	for (i=0;i<R+2;i++){
		for (j=0;j<C+2;j++)
			printf ("%3d",M[i][j]);
		printf("\n");
	}	
	printf("\n");
	printf ("移动坐标为：\n"); 
	Maze(1,1);
	printf ("(1,1)");
	return 0;
}
