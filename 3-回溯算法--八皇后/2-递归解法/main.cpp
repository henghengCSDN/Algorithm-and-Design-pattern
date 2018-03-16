#include <stdio.h>

/*
宏定义： 
	col:存储列是否放了皇后的数组；
	left:存储左斜线是否有放皇后的数组；
	right:存储右斜线是否有放皇后的数组
	Q[8]:存储皇后的数组 
	cnt:计数器变量 
*/
int col[8] = {0};	//列的下标(j)数组
int left[15]= { 0 };	//左斜线数组
int right[15]= { 0 };	//右斜线数组
int Q[8];
int cnt;	//计数器 

/*
函数名：print
函数作用：输出皇后的坐标及棋盘
函数参数：i,j：控制循环次数的变量
不带参，无返回值 
*/
void print (){
	int i,j;
	printf ("\n\n第%d组解为：\n",++cnt);
	for (i = 0; i < 8; i++)
		printf("\t%d", Q[i]);
	printf("\n\n");
	printf("棋盘显示：\n\n");
	for (i=0;i<8;i++){
		for (j=0;j<8;j++){
			if (Q[7-i]==j)
				printf ("\tQ");
			else
				printf("\t*");
		}
		printf("\n");
	}
} 

/*
函数名：Queen 
函数作用：找出所有的皇后位置并输出打印 
函数参数：top:假栈数组（Q[8]）的下标,模拟栈顶指针 。i:行的标志。j：列的标志 
带参i，i:行遍历的起点坐标 
无返回值 
*/
void Queen(int i) {
	int j;
	for (j=0;j<8;j++){
		if (!col[j] && !left[i + j] && !right[7 + i - j]){
			Q[i]=j;
			col[j]=left[i+j]=right[7+i-j]=1;
			if (i<7)
				Queen (i+1);
			else
				print ();
			col[j]=left[i+j]=right[7+i-j]=0;	//抹皇后 
		}
	}
}

/*
主函数
函数作用：调用子函数 ,程序运行的起点 
*/
int main (void){
	int i=0;
	Queen (i);
	return 0;
}
