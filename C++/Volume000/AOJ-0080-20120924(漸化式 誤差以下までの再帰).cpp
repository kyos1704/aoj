#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double ans(int q,double x){
	x=x-(x*x*x-q)/(3*x*x);
	if((x*x*x-double(q)<0.000001*double(q))&&(x*x*x-double(q)>-0.000001*double(q))){
		return x;
	}else{
		return ans(q,x);
	}
	
}


int main(){
	int q;
	double x;
	while(scanf("%d",&q),q!=-1){
		x=ans(q,double(q)/2);
		printf("%lf\n",x);
	}
}
