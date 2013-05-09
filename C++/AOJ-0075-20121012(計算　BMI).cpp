#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int num=0;
	double w=0,h=0;
	
	while((scanf("%d,%lf,%lf",&num,&w,&h))!=EOF){
		if(w/(h*h)>=25){
			cout<<num<<endl;
		}
	}
}

