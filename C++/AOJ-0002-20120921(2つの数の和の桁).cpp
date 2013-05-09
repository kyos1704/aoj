#include<iostream>
using namespace std;

int main(){
	int a,b;
	while(cin>>a>>b){
		a=a+b;
		for(b=0;a>0;b++){
			a=a/10;
		}
		cout<<b<<endl;
	}
	return 0;
	
}
