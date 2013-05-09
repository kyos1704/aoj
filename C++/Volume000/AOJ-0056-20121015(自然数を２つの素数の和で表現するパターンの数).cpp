#include<iostream>
#include <algorithm>
#include<functional>//greater‚ÌŽg—p
using namespace std;
#define MAX_LIST 50000

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
	int primelist[MAX_LIST];
	int j=0;
	for(int i=0;i<MAX_LIST;i++){
		if(prime[i]==1){
			primelist[j]=i;
			j++;
			if(j>MAX_LIST){
				break;
			}
		}
	}
	int in;
	while(cin>>in,in){
		int ans=0;
		for(int i=0;primelist[i]*2<=in;i++){
			if(prime[in-primelist[i]]==1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
