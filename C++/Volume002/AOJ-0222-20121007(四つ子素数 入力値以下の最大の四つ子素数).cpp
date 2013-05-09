#include<iostream>
#include <algorithm>
using namespace std;
#define MAX_LIST 10000000 



int main(){
	bool *prime=(bool *)malloc(sizeof(bool)*MAX_LIST);
	//bool prime[MAX_LIST];
	for(int i=0;i<MAX_LIST;i++){
		prime[i]=1;
	}
	prime[0]=prime[1]=0;
	for(int i=0;i*i<MAX_LIST;i++){
		if(prime[i]==1){ 
			for(int j=i*2;j<MAX_LIST;j=j+i){
				prime[j]=0;
			}
		}
	}
	int n;
	while(cin>>n,n){
		int ans=0;
		for(int i=n;i>0;i--){
			if((prime[i]==1)
				&&(prime[i-2]==1)
				&&(prime[i-6]==1)
				&&(prime[i-8]==1)){
				ans=i;
				break;
			}
			
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
