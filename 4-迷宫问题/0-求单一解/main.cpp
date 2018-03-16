#include <stdio.h>

#define R 7
#define C 8

//���岢��ʼ���Թ� 
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
int t[R+2][C+2]={0};	//��־���ߵ�·������ 
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};	//�����ƶ�̽������� 
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
			t[a][b]=1;	//��־���ߵ�·
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
	printf("ԭ�Թ�Ϊ��\n");
	for (i=0;i<R+2;i++){
		for (j=0;j<C+2;j++)
			printf ("%3d",M[i][j]);
		printf("\n");
	}	
	printf("\n");
	printf ("�ƶ�����Ϊ��\n"); 
	Maze(1,1);
	printf ("(1,1)");
	return 0;
}
