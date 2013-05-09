#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include <utility>

using namespace std;


int main(){
	int dp[10100];
	
	int W,N;
	int v[1010],w[1010];
	
	int count=0;
	
	while(cin>>W,W){
		cin>>N;
		count++;
		for(int i=0;i<N;i++){
			scanf("%d,%d",&v[i],&w[i]);
		}
		
		for(int j=0;j<W+1;j++){
			if(j<w[0]){
				dp[j]=0;
			}else{
				dp[j]=v[0];
			}
		}
		
		for(int i=1;i<N;i++){
			for(int j=W;j;j--){
				if(j<w[i]){
					dp[j]=dp[j];
				}else{
					dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
				}
			}
		}
		cout<<"Case "<<count<<":"<<endl;
		cout<<dp[W]<<endl;
		while(dp[W]==dp[W-1])W--;
		cout<<W<<endl;
	}
	
	
	
	
	return 0;
	
}

