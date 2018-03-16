#include <stdio.h>

/*
宏定义： 
	col存储列是否放了皇后的数组；
	left存储左斜线是否有放皇后的数组；
	right存储右斜线是否有放皇后的数组
	Q[8]存储皇后的数组，模拟栈 
*/
int col[8] = {0};	//列的下标(j)数组
int left[15]= { 0 };	//左斜线数组
int right[15]= { 0 };	//右斜线数组
int Q[8];	//储存皇后所用的栈
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
不带参，无返回值 
*/
void Queen() {
	int top = -1;
	int i = 0, j = 0;
	while (1){
		while (top != 7) {
			for (; j < 8; j++) {
				if (!col[j] && !left[i + j] && !right[7 + i - j]) {
					Q[++top] = j;
					col[j] = left[i + j] = right[7 + i - j] = 1;
					i++;
					j = 0;
					break;
				}
			}
			//不能放
			if(j == 8 && i>0){
				i--;
				j = Q[top--];
				col[j] = left[i + j] = right[7 + i - j] = 0;
				j++	;
			}
		}
		//输出
		if (j == 8)
			break;
		print ();
		//回溯 
		i--;
		j = Q[top--];
		col[j] = left[i + j] = right[7 + i - j] = 0;
		j++;
	}	
}

/*
主函数
函数作用：调用子函数 ,程序运行的起点 
*/
int main(void) {
	
	Queen();
	getchar();
}
