#include <iostream>
#include<string>
using namespace std;


int main(){
	bool prime[60000];
	for(int i=0;i<60000;i++){
		prime[i]=1;
	}
	prime[0]=prime[1]=0;
	for(int i=0;i*i<60000;i++){
		if(prime[i]==1){
			for(int j=i*2;j<60000;j+=i){
				prime[j]=0;
			}
		}
	}
	int n;
	while(cin>>n){
		int i;
		for(i=1;prime[n-i]==0;i++);
		cout<<n-i<<" ";
		for(i=1;prime[n+i]==0;i++);
		cout<<n+i<<endl;
	}
}

