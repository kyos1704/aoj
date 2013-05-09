#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int a,b;
	while(cin>>a>>b){
		a=a+b;
		b=log10(a)+1;
		cout<<b<<endl;
	}
	return 0;
	
}
