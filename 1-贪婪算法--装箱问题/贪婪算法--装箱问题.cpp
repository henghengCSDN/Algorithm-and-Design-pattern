#include <stdio.h>
#include <stdlib.h>

#define V 50	//����������� 

//�����Ʒ��Ϣ���������� 
typedef struct{
	int gno;	//��Ʒ���
	int gv;		//��Ʒ��� 
}ElemG;

//��Ʒ�����������
typedef struct node {
	int gno;
	struct node *link;
}Goodslink;

//���ӵĽ������
typedef struct box {
	int remainder;	//���ӵ�ʣ�����
	Goodslink *hg;	//ָ����Ʒ����ָ��
	struct box *next;	//ָ����һ������ָ�� 
}boxlink;

//ȫ�ֶ���һЩ���� 
ElemG *g;
int vol,N,k;
boxlink *hbox,*p,*tail;
Goodslink *q,*rear;

//�Ӻ�������	
void initgoods(); 
void sort (); 
void encasement (); 
void print ();

//������ 
int main (void) {
	printf ("��������Ʒ������");
	scanf ("%d",&N); 
	//���ٴ���Ʒ�Ŀռ� 
	g=(ElemG *) malloc (N * sizeof (ElemG)); 
	
	//��ʼ����Ʒ	
	initgoods(); 

	//�������� 
	sort (); 
	
	//װ��
	encasement (); 
	
	//���
	print (); 
}

/*
* ��������initgoods
* ���ܣ���ʼ����Ʒ 
* ��������
* ����ֵ���� 
*/
void initgoods(){
	for (int i=0;i<N;i++) {
		g[i].gno=i+1;
		printf ("�������%d����Ʒ�������",i+1);
		scanf ("%d",&vol);
		//��ֹ��Ʒ��������������,������Ʒ���Ϊ���� 
		if ( vol > 0 && vol <= V ){
			g[i].gv=vol;
		}
		else {
			printf ("����Ʒ���������Χ�����������룡\n");
			i--;
		}
	}
}

/*
 * ��������sort
 * ���ܣ���������Ʒ�������С�������� 
 * ��������
 * ����ֵ���� 
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
 * ��������encasement
 * ���ܣ�����Ʒװ������ 
 * ��������
 * ����ֵ���� 
 */
 void  encasement (){
 	//�������е�������Ʒ
	for (int i=0;i<N;i++){
		//����������
		for (p=hbox;p && p->remainder <g[i].gv;p=p->next) {
			;
		}
		//���û�������ܷ��£���������
		if (!p){
			//��ʼ������ 
			p=(boxlink *) malloc (sizeof(boxlink));
			p->remainder=V;
			p->hg=NULL;
			p->next=NULL;
			//������
			if(!hbox)
				hbox=tail=p;
			else
				tail=tail->next=p; 
		}
		p->remainder=p->remainder-g[i].gv;		//��������Ŀռ� 
		//����Ʒ
		//������Ʒ��� 
		q=(Goodslink *) malloc (sizeof(Goodslink));
		q->gno=g[i].gno;
		q->link=NULL;
		//
		if (!p->hg)
			p->hg=q;
		else{
			for (rear=p->hg;rear->link;rear=rear->link)
				; //��rearָ���ܵ���Ʒ��β��
			rear->link=q;	//����Ʒ 
		}
	}
 }
 
/*
* ��������print
* ���ܣ���ӡװ����� 
* ��������
* ����ֵ���� 
*/	
void print () {
	for(k=1,p=hbox;p;p=p->next){
		printf ("��%d��������Ʒ�У�",k++);
		for (q=p->hg;q;q=q->link){
			printf("%d\t",q->gno);
		}
		printf ("\n");
	} 
}
