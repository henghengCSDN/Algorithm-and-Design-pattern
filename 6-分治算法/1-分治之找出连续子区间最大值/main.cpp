#include<stdio.h>

#define N 9

//max连续子区间最大值  mx数据中的第mx开始 到my个结束 
int max,mx,my; 

/*
函数作用：找出连续子区间最大值及其位置
函数参数：所分的开始点X及结束点y  maxl左分的最大值  maxr右分的最大值 
 maxz中间区域最大值  maxzl中间区域左边最大值 maxzr中间区域右边最大值
返回值：当前的最大值max 
*/
int MaxSum(int a[],int x,int y){
	int m,maxl,maxr,maxz,maxzl,maxzr; 
	int i,j,mi,mj,sum;
	//二分成只剩一个数据时返回这个数 
	if(y-x==1)
		return a[x];
	m=x+(y-x)/2;
	maxl=MaxSum(a,x,m);
	maxr=MaxSum(a,m,y);
	//取左右中的最大值 
	max=maxl;
	mx=x+1;
	my=m+1;
	if(maxr>maxl){
		max=maxr;
		mi=m+1;
		mj=y+1;	
	} 
	//取中间左边最大值 
	maxzl=a[m-1];
	sum=0;
	for(i=m-1;i>x-1;--i){
		sum+=a[i];
		if(maxzl<sum){
			maxzl=sum;	
			mi=i+1;
		}	
	}
	//取中间右边最大值 
	maxzr=a[m];
	sum=0;
	for(j=m;j<y;++j){
		sum+=a[j];
		if(maxzr<sum){
			maxzr=sum;
			mj=j+1;
		}	
	}
	//左右加起来中间最大值 
	maxz=maxzl+maxzr;
	//判断左右最大与中间最大值 
	if(max<maxz){
		max=maxz;
		mx=mi;
		my=mj;
	}
	return max ; 
} 
int main (void){
	int a[N]={1,2,3,4,5,6,7,8,9};
	//调求找出连续子区间最大值及其位置
	max=MaxSum(a,0,N);
	printf("和值最大的区间为：[%d,%d]\n最大连续区间内的数之和为：%d",mx,my,max);
	return 0;
}
