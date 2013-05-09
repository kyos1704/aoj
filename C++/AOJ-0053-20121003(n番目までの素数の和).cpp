#include<iostream>
using namespace std;
#define MAX_LIST 105000

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
	int primelist[10000];
	int j=0;
	for(int i=0;i<MAX_LIST;i++){
		if(prime[i]==1){
			primelist[j]=i;
			j++;
			if(j>10000-1){
				break;
			}
		}
	}
	int ans;
	while(cin>>j,j){
		ans=0;
		for(int i=0;i<j;i++){
			ans=ans+primelist[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
