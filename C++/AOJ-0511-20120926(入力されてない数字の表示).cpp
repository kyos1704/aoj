#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int n;
	bool t[31];
	for(int i=0;i<31;i++){
		t[i]=0;
	}
	for(int i=0;i<28;i++){
		cin>>n;
		t[n]=1;
	}
	for(int i=1;i<31;i++){
		if(t[i]==0){
			cout<<i<<endl;
		}
	}
}
