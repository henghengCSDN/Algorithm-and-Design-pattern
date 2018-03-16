#include <stdio.h>

/*
�궨�壺 
	col:�洢���Ƿ���˻ʺ�����飻
	left:�洢��б���Ƿ��зŻʺ�����飻
	right:�洢��б���Ƿ��зŻʺ������
	Q[8]:�洢�ʺ������ 
	cnt:���������� 
*/
int col[8] = {0};	//�е��±�(j)����
int left[15]= { 0 };	//��б������
int right[15]= { 0 };	//��б������
int Q[8];
int cnt;	//������ 

/*
��������print
�������ã�����ʺ�����꼰����
����������i,j������ѭ�������ı���
�����Σ��޷���ֵ 
*/
void print (){
	int i,j;
	printf ("\n\n��%d���Ϊ��\n",++cnt);
	for (i = 0; i < 8; i++)
		printf("\t%d", Q[i]);
	printf("\n\n");
	printf("������ʾ��\n\n");
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
��������Queen 
�������ã��ҳ����еĻʺ�λ�ò������ӡ 
����������top:��ջ���飨Q[8]�����±�,ģ��ջ��ָ�� ��i:�еı�־��j���еı�־ 
����i��i:�б������������ 
�޷���ֵ 
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
			col[j]=left[i+j]=right[7+i-j]=0;	//Ĩ�ʺ� 
		}
	}
}

/*
������
�������ã������Ӻ��� ,�������е���� 
*/
int main (void){
	int i=0;
	Queen (i);
	return 0;
}
