#include <stdio.h>
#include <stdlib.h>

//��� 
typedef struct node {
	char word;	//�ַ�
	int weight;	//Ȩֵ
	struct node *left,*right;	//����ָ��
}HuffNode;

//HuffmanTreeʵ��
HuffNode *GreateHuffmanTree(HuffNode * *F,int n){
	int loop,i,k1,k2;
	HuffNode *pa;
	for (loop=1;loop<n;loop++){
		for(k1=0;k1<n && !F[k1];k1++)
			;
		for (k2=k1+1;k2<n && !F[k2];k2++)
			;
		for (i=k2;i<n;i++){
			if (F[i]){
				if (F[i]->weight < F[k1]->weight){
					k2=k1;
					k1=i;
				}
				else
					if (F[i]->weight < F[k2]->weight){
						k2=i;
					}
			}
		}
		pa=(HuffNode *) malloc (sizeof (HuffNode));
		pa->word='X';
		pa->weight=F[k1]->weight+F[k2]->weight;
		pa->left=F[k1];
		pa->right=F[k2];
		F[k1]=pa;
		F[k2]=NULL;
	}
	return F[k1];
}

//���(ǰ�����)
void print (HuffNode * root){
	if (root){
		printf ("%c\t",root->word);
		print(root->left);
		print(root->right);	
	}
} 

int main(void) {
	//����ɭ�� 
	HuffNode *root;
	HuffNode **F;
	int n;	//Ҷ����
	char ch;
	int w,i;
	printf ("������Ҷ������");
	scanf ("%d",&n); 
	F=(HuffNode **) malloc (n*sizeof(HuffNode *));
	//��ʼ��ɭ��
	for (int i=0;i<n;i++) {
		F[i]=(HuffNode *) malloc (sizeof (HuffNode));
		F[i]->left=F[i]->right=NULL;
		printf ("�������ַ���");
		fflush(stdin);
		scanf ("%c",&ch);
		fflush(stdin);
		printf ("������Ȩֵ��");
		scanf("%d",&w);
		fflush(stdin);
		F[i]->word=ch;
		F[i]->weight=w; 
	}
	//����HuffmanTree
	root=GreateHuffmanTree(F,n);
	//���
	print(root); 
	return 0;
}  














