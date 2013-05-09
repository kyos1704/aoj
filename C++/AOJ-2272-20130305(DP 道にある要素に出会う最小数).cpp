#include<iostream>
#include<string>
#include<climits>
using namespace std;



int main(){
	int dp[60][60];
	int map[60][60]={0};
	for(int i=0;i<60;i++){
		for(int j=0;j<60;j++){
			dp[i][j]=INT_MAX;
		}
	}
	string s;
	int H,W;
	cin>>H>>W;
	for(int i=0;i<H;i++){
		cin>>s;
		for(int j=0;j<s.size();j++){
			map[i+1][j+1]=s[j]-'0';
		}
	}
	dp[1][1]=0;
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i][j-1]))+map[i][j];
		}
	}
	cout<<dp[H][W]<<endl;
	
}