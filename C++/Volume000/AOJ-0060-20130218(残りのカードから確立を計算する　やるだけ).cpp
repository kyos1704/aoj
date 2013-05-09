#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;


int main(){
	int a[3];
	bitset<11> cards;
	while(cin>>a[0]>>a[1]>>a[2]){
		cards.reset();
		int sum=a[0]+a[1];
		int ans=0;
		cards[a[0]]=1;
		cards[a[1]]=1;
		cards[a[2]]=1;
		for(int i=1;i<11;i++){
			//cout<<cards[i];
			if(sum+i<=20&&cards[i]==0){
				ans++;
			}
		}
		//cout<<endl;
		//cout<<ans<<endl;
		if(ans*2>7){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}