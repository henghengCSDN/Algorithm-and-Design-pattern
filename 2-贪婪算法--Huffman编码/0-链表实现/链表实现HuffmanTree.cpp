#include <stdio.h>
#include <stdlib.h>

//结点 
typedef struct node {
	char word;	//字符
	int weight;	//权值
	struct node *left,*right;	//左右指针
}HuffNode;

//HuffmanTree实现
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

//输出(前序遍历)
void print (HuffNode * root){
	if (root){
		printf ("%c\t",root->word);
		print(root->left);
		print(root->right);	
	}
} 

int main(void) {
	//定义森林 
	HuffNode *root;
	HuffNode **F;
	int n;	//叶子数
	char ch;
	int w,i;
	printf ("请输入叶子数：");
	scanf ("%d",&n); 
	F=(HuffNode **) malloc (n*sizeof(HuffNode *));
	//初始化森林
	for (int i=0;i<n;i++) {
		F[i]=(HuffNode *) malloc (sizeof (HuffNode));
		F[i]->left=F[i]->right=NULL;
		printf ("请输入字符：");
		fflush(stdin);
		scanf ("%c",&ch);
		fflush(stdin);
		printf ("请输入权值：");
		scanf("%d",&w);
		fflush(stdin);
		F[i]->word=ch;
		F[i]->weight=w; 
	}
	//创建HuffmanTree
	root=GreateHuffmanTree(F,n);
	//输出
	print(root); 
	return 0;
}  














