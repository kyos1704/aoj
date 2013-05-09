#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


int main(){
	int t=0,h=0;
	
	int x,y,z;
	while(scanf("%d,%d,%d",&x,&y,&z)!=EOF){
		if(x*x+y*y==z*z){
			t++;
		}
		if(x==y){
			h++;
		}
	}
	cout<<t<<endl<<h<<endl;
	
	return 0;
}
  