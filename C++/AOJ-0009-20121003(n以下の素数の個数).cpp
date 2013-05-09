#include<iostream>
using namespace std;
#define MAX_LIST 1000000

int main(){
	bool prime[MAX_LIST];
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
	while(cin>>n){
		int count=0;
		for(int i=0;i<=n;i++){
			if(prime[i]==1){
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
