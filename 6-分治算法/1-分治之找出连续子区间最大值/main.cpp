#include<stdio.h>

#define N 9

//max�������������ֵ  mx�����еĵ�mx��ʼ ��my������ 
int max,mx,my; 

/*
�������ã��ҳ��������������ֵ����λ��
�������������ֵĿ�ʼ��X��������y  maxl��ֵ����ֵ  maxr�ҷֵ����ֵ 
 maxz�м��������ֵ  maxzl�м�����������ֵ maxzr�м������ұ����ֵ
����ֵ����ǰ�����ֵmax 
*/
int MaxSum(int a[],int x,int y){
	int m,maxl,maxr,maxz,maxzl,maxzr; 
	int i,j,mi,mj,sum;
	//���ֳ�ֻʣһ������ʱ��������� 
	if(y-x==1)
		return a[x];
	m=x+(y-x)/2;
	maxl=MaxSum(a,x,m);
	maxr=MaxSum(a,m,y);
	//ȡ�����е����ֵ 
	max=maxl;
	mx=x+1;
	my=m+1;
	if(maxr>maxl){
		max=maxr;
		mi=m+1;
		mj=y+1;	
	} 
	//ȡ�м�������ֵ 
	maxzl=a[m-1];
	sum=0;
	for(i=m-1;i>x-1;--i){
		sum+=a[i];
		if(maxzl<sum){
			maxzl=sum;	
			mi=i+1;
		}	
	}
	//ȡ�м��ұ����ֵ 
	maxzr=a[m];
	sum=0;
	for(j=m;j<y;++j){
		sum+=a[j];
		if(maxzr<sum){
			maxzr=sum;
			mj=j+1;
		}	
	}
	//���Ҽ������м����ֵ 
	maxz=maxzl+maxzr;
	//�ж�����������м����ֵ 
	if(max<maxz){
		max=maxz;
		mx=mi;
		my=mj;
	}
	return max ; 
} 
int main (void){
	int a[N]={1,2,3,4,5,6,7,8,9};
	//�����ҳ��������������ֵ����λ��
	max=MaxSum(a,0,N);
	printf("��ֵ��������Ϊ��[%d,%d]\n������������ڵ���֮��Ϊ��%d",mx,my,max);
	return 0;
}
