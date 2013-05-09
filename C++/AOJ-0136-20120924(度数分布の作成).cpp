#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int map[6];
	for(int i=0;i<6;i++){
		map[i]=0;
	}
	int n;
	double length;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>length;
		if(length<165.0){
			map[0]++;
		}else if(length<170.0){
			map[1]++;
		}else if(length<175.0){
			map[2]++;
		}else if(length<180.0){
			map[3]++;
		}else if(length<185.0){
			map[4]++;
		}else{
			map[5]++;
		}
	}
	
	
	for(int i=0;i<6;i++){
		cout<<i+1<<":";
		for(int j=0;j<map[i];j++){
			cout<<"*";
		}
		cout<<endl;
	}
	
}
