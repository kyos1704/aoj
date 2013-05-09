#include<iostream>
#include <algorithm>
#include<functional>//greater‚ÌŽg—p
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
	int *prime_num=(int*)malloc(sizeof(int)*MAX_LIST);
	//int prime_num[MAX_LIST];
	prime_num[0]=1;
	for(int i=1;i<MAX_LIST;i++){
		prime_num[i]=prime_num[i-1]+prime[i];
	}
	
	
	int n;
	while(cin>>n,n){
		int ans=0;
		ans=prime_num[2*n]-prime_num[n];
		cout<<ans<<endl;
	}
	return 0;
}
