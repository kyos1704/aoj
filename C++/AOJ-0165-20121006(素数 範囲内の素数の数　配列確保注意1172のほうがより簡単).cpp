#include<iostream>
#include <algorithm>
#include<functional>//greater‚ÌŽg—p
using namespace std;
#define MAX_LIST 999983+100
#define MP 999983

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
	for(int i=MP+1;i<MAX_LIST;i++){
		prime[i]=0;
	}
	int *prime_num=(int*)malloc(sizeof(int)*MAX_LIST);
	//int prime_num[MAX_LIST];
	prime_num[0]=1;
	for(int i=1;i<MAX_LIST;i++){
		prime_num[i]=prime_num[i-1]+prime[i];
	}
	
	
	int pair_num;
	while(cin>>pair_num,pair_num){
		int ans=0;
		for(int i=0;i<pair_num;i++){
			int p,m;
			cin>>p;
			cin>>m;
			int x=0;
			int a,b;
			if(p+m>MP){
				a=MP;
			}else{
				a=p+m;
			}
			if(p-m<0){
				b=0;
			}else{
				b=p-m;
			}
			x=prime_num[a]-prime_num[b]+prime[b];
			
			if(x==0){
				ans--;
			}else{
				x--;
				ans=ans+x;
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
