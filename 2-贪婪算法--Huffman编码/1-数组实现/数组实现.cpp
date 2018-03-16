#include <stdio.h>
#include <stdlib.h>

//�ṹ������
typedef struct {
	char word;
	int weight;
	int left,right,parent;
	int *code;
}Huff;

//����ʵ��HuffmanTree 
Huff * GreateHuffmanTree (Huff *F,int n){
	int loop,k1,k2,i;
	for (loop=0;loop<n-1;loop++){
		for (k1=0;k1<n+loop && F[k1].parent!=-1;k1++)
			;
		for (k2=k1+1;k2<n+loop && F[k2].parent!=-1;k2++)
			;
		for (i=k2;i<n+loop;i++){
			if (F[i].parent==-1){
				if (F[i].weight < F[k1].weight){
					k2=k1;
					k1=i;
				}
				else
					if (F[i].weight < F[k2].weight)
						k2=i;
			}
		}
		F[i].word='X';
		F[i].weight=F[k1].weight+F[k2].weight;
		F[i].left=k1;
		F[i].right=k2;
		F[i].parent=-1;
		F[k1].parent=F[k2].parent=i;	
	}
	return F;
}

//����
void GreateHuffCode(Huff *F,int n){
	int c,pa,i;
	int *p;
	for (i=0;i<n;i++){
		p=F[i].code=(int *) malloc (n * (sizeof(int)));
		p[0]=0;
		c=i;
		while(F[c].parent != -1){
			pa=F[c].parent;
			if (F[pa].left==c)
				p[++p[0]]=0;
			else
				p[++p[0]]=1;
			c=pa;
		}
	}
} 

//���
void print (Huff *F ,int n){
	int i,j;
	int *q;
	printf ("���Ϊ��\n");
	printf("\tNO.\tword\tweight\tleft\tright\tparent\t����\n");
	for (i=0;i<(2*n-1);i++){
		q=F[i].code;
		printf("\t%d\t%3c\t%3d\t%3d\t%3d\t%3d\t",i,F[i].word,F[i].weight,F[i].left,F[i].right,F[i].parent);
		if (i<n){
			for (j=q[0];j>=1;j--){
				printf("%d",q[j]);
			}
		}
		printf("\n");
	}
} 


int main (void){
	//�����ṹ������
	Huff *F;
	int i,n,w;
	char ch;
	printf ("������Ҷ������");
	scanf ("%d",&n);
	fflush(stdin);
	F=(Huff *) malloc ((2*n-1) * (sizeof(Huff)));
	//��ʼ��
	for (i=0;i<n;i++){
		printf("�������ַ�:");
		scanf ("%c",&ch);
		fflush(stdin);
		printf ("������Ȩֵ��");
		scanf("%d",&w);
		fflush(stdin);
		F[i].word=ch;
		F[i].weight=w;
		F[i].left=F[i].right=F[i].parent=-1;
	} 
	//ʵ�ֶ�����
	F=GreateHuffmanTree(F,n);
	//��������
	GreateHuffCode(F,n);
	//���
	print (F ,n);
	return 0;
} 
