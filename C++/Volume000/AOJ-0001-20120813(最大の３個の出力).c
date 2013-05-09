#include<stdio.h>

void swap(int* a,int x,int y){
	int c;
	c=a[x];
	a[x]=a[y];
	a[y]=c;
	return;
}


int main(){
	int a[4]={0,0,0,0};
	int i,j,k;
	int c;
	for(i=10;i--;){
		scanf("%d",&a[3]);
		if(a[3]>a[2]){
			swap(a,0,1);
			swap(a,1,2);
			swap(a,2,3);
		}else if(a[3]>a[1]){
			swap(a,0,1);
			swap(a,1,3);
		}else if(a[3]>a[0]){
			swap(a,0,3);
		}
	}
	
	for(i=3;i--;){
		printf("%d\n",a[i]);
	}
	return 0;
}


