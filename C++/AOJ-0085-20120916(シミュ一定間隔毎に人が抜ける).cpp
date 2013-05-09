#include<stdio.h>
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int main(){
	int n,m;
	while(scanf("%d %d",&n,&m),n!=0){
		queue<int> chair;
		for(int i=0;i<n;i++){
			chair.push(i);
		}
		int ans=0;
		while(chair.empty()!=true){
			for(int j=m-1;j--;){
				int n;
				n=chair.front();chair.pop();
				chair.push(n);
			}
			ans=chair.front();chair.pop();
		}
		
		cout<<ans+1<<endl;
	}
	
}
