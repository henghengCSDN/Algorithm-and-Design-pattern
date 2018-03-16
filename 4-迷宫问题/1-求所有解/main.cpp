#include <stdio.h>

#define R 7
#define C 8

//���岢��ʼ���Թ� 
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
int t[R+2][C+2]={0};	//��־���ߵ�·������ 
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};	//�����ƶ�̽������� 
int cnt=0,top=1;
int tag=0;
int stack[100][2];

void print(){
	int i;
	printf("\n");
	printf ("��%d��·��������Ϊ��\n",++cnt);
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
	if (x==7 && y==8){	//�ǳ��� 
		print();
		tag=1;  
	} 
	else{				//�ǳ��� 
		for (i=0;i<4;i++){
			a=x+Move[i][0];
			b=y+Move[i][1];
			if (M[a][b]==0 && !t[a][b]){
				t[a][b]=1;	//��־���ߵ�·
				stack[top][0]=a;
				stack[top++][1]=b;
				Maze(a,b);
				t[a][b]=0;	//Ĩ��� 
				top--; 
			} 
		}
	}
} 

int main (void){
	int i, j;
	printf("ԭ�Թ�Ϊ��\n");
	for (i=0;i<R+2;i++){
		for (j=0;j<C+2;j++)
			printf ("%3d",M[i][j]);
		printf("\n");
	}
	stack[0][0]=1;
	stack[0][1]=1;
	Maze(1,1);
	if (tag==0)
		printf ("\n��·���ߣ�\n");
	return 0;
}
