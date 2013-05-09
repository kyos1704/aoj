#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	
	double max=-1,min=-1,n;
	
	while(scanf("%lf",&n)!=EOF){
		if(n>max||max==-1){
			max=n;
		}
		if(n<min||min==-1){
			min=n;
		}
	}
	
	cout<<max-min<<endl;
}
