#include <stdio.h>

#define R 7
#define C 8

//定义并初始化迷宫 
int M[R+2][C+2]={
				 {1,1,1,1,1,1,1,1,1,1},
				 {1,0,1,1,1,1,1,1,1,1},
				 {1,0,1,1,1,1,1,1,1,1},
				 {1,0,0,0,0,1,1,1,1,1},
				 {1,0,1,1,0,0,0,0,1,1},
				 {1,0,0,1,1,0,0,0,1,1},
				 {1,1,1,1,0,0,0,1,1,1},
				 {1,1,1,1,0,0,0,0,0,1},
				 {1,1,1,1,1,1,1,1,1,1}
				};
int t[R+2][C+2]={0};	//标志已走的路的数组 
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};	//定义移动探查的数组 
int cnt=0,top=1;
int tag=0;
int stack[100][2];

void print(){
	int i;
	printf("\n");
	printf ("第%d条路坐标依次为：\n",++cnt);
	for (i=0;i<top;i++){
		if (i==top-1)
			printf("(%d,%d)",stack[i][0],stack[i][1]);
		else
			printf("(%d,%d)->",stack[i][0],stack[i][1]);
	}	
	printf("\n\n"); 
}

int Maze (int x,int y){
	int i;
	int a=0,b=0;
	if (x==7 && y==8){	//是出口 
		print();
		tag=1;  
	} 
	else{				//非出口 
		for (i=0;i<4;i++){
			a=x+Move[i][0];
			b=y+Move[i][1];
			if (M[a][b]==0 && !t[a][b]){
				t[a][b]=1;	//标志已走的路
				stack[top][0]=a;
				stack[top++][1]=b;
				Maze(a,b);
				t[a][b]=0;	//抹标记 
				top--; 
			} 
		}
	}
} 

int main (void){
	int i, j;
	printf("原迷宫为：\n");
	for (i=0;i<R+2;i++){
		for (j=0;j<C+2;j++)
			printf ("%3d",M[i][j]);
		printf("\n");
	}
	stack[0][0]=1;
	stack[0][1]=1;
	Maze(1,1);
	if (tag==0)
		printf ("\n无路可走！\n");
	return 0;
}
