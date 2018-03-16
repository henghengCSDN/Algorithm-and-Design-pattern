#include <stdio.h>
#include <stdlib.h>

#define V 50	//箱子体积定义 

//存放物品信息的类型声明 
typedef struct{
	int gno;	//物品编号
	int gv;		//物品体积 
}ElemG;

//物品结点类型声明
typedef struct node {
	int gno;
	struct node *link;
}Goodslink;

//箱子的结点类型
typedef struct box {
	int remainder;	//箱子的剩余体积
	Goodslink *hg;	//指向物品结点的指针
	struct box *next;	//指向下一个结点的指针 
}boxlink;

//全局定义一些变量 
ElemG *g;
int vol,N,k;
boxlink *hbox,*p,*tail;
Goodslink *q,*rear;

//子函数声明	
void initgoods(); 
void sort (); 
void encasement (); 
void print ();

//主函数 
int main (void) {
	printf ("请输入物品个数：");
	scanf ("%d",&N); 
	//开辟存物品的空间 
	g=(ElemG *) malloc (N * sizeof (ElemG)); 
	
	//初始化物品	
	initgoods(); 

	//降序排序 
	sort (); 
	
	//装箱
	encasement (); 
	
	//输出
	print (); 
}

/*
* 函数名：initgoods
* 功能：初始化物品 
* 参数：无
* 返回值：无 
*/
void initgoods(){
	for (int i=0;i<N;i++) {
		g[i].gno=i+1;
		printf ("请输入第%d个物品的体积：",i+1);
		scanf ("%d",&vol);
		//防止物品体积大于箱子体积,或者物品体积为负数 
		if ( vol > 0 && vol <= V ){
			g[i].gv=vol;
		}
		else {
			printf ("该物品体积超出范围，请重新输入！\n");
			i--;
		}
	}
}

/*
 * 函数名：sort
 * 功能：将所有物品按体积大小降序排序 
 * 参数：无
 * 返回值：无 
 */
void sort (){
	int i,j,t,tag=1;
	for (i=0;tag && i<N;i++){
		tag=0;
		for(j=0;j<N-i;j++)
			if (g[j].gv>g[j-1].gv)
			{
				t=g[j].gno;
				g[j].gno=g[j-1].gno;
				g[j-1].gno=t;
				
				t=g[j].gv;	
				g[j].gv=g[j-1].gv;
				g[j-1].gv=t;
				tag=1;
			}
	}
} 
/*
 * 函数名：encasement
 * 功能：将物品装入箱子 
 * 参数：无
 * 返回值：无 
 */
 void  encasement (){
 	//遍历所有的排序物品
	for (int i=0;i<N;i++){
		//遍历箱子链
		for (p=hbox;p && p->remainder <g[i].gv;p=p->next) {
			;
		}
		//如果没有箱子能放下，则开新箱子
		if (!p){
			//初始化箱子 
			p=(boxlink *) malloc (sizeof(boxlink));
			p->remainder=V;
			p->hg=NULL;
			p->next=NULL;
			//挂箱子
			if(!hbox)
				hbox=tail=p;
			else
				tail=tail->next=p; 
		}
		p->remainder=p->remainder-g[i].gv;		//减掉放入的空间 
		//放物品
		//创建物品结点 
		q=(Goodslink *) malloc (sizeof(Goodslink));
		q->gno=g[i].gno;
		q->link=NULL;
		//
		if (!p->hg)
			p->hg=q;
		else{
			for (rear=p->hg;rear->link;rear=rear->link)
				; //将rear指针跑到物品链尾部
			rear->link=q;	//挂物品 
		}
	}
 }
 
/*
* 函数名：print
* 功能：打印装箱情况 
* 参数：无
* 返回值：无 
*/	
void print () {
	for(k=1,p=hbox;p;p=p->next){
		printf ("第%d个箱子物品有：",k++);
		for (q=p->hg;q;q=q->link){
			printf("%d\t",q->gno);
		}
		printf ("\n");
	} 
}
