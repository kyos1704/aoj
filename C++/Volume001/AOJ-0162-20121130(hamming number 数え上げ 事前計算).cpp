#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define MAX 1000010

int main(){
	int hamming[MAX];
	for(int i=0;i<MAX;i++){
		hamming[i]=0;
	}
	long int tmp =0;
	for(int i=0;tmp<MAX;i++){
		for(int j=0;tmp<MAX;j++){
			for(int k=0;tmp<MAX;k++){
				tmp =pow(2,i)*pow(3,j)*pow(5,k);
				if(tmp<MAX){
					hamming[tmp]=1;
				}
			}
			tmp =pow(2,i)*pow(3,j+1)*pow(5,0);
		}
		tmp =pow(2,i+1)*pow(3,0)*pow(5,0);
	}
	
	
	int a,b;
	while(cin>>a,a!=0){
		cin>>b;
		int ans=0;
		for(int i=a;i<b+1;i++){
			ans+=hamming[i];
		}
		cout<<ans<<endl;
	}
	
}