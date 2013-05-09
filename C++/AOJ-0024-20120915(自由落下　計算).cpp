#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	
	double n;
	
	while(scanf("%lf",&n)!=EOF){
		n=n/9.8;
		n=n*n*4.9;
		int i;
		for(i=1;i*5-5<n;i++);
		cout<<i<<endl;
	}
	return 0;
}
  