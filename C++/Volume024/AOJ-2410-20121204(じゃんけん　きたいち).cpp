#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;


int main(){
	char judge[20][20];
	int N;
	int ai_hand;
	int max[20];
	int max_hand=0;
	int max_hand_win=0;
	int out_hand;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>judge[i];
		max[i]=0;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(judge[i][j]=='o'){
				max[i]+=3;
			}
			if(judge[i][j]=='-'){
				max[i]+=1;
			}
		}
	}
	for(int i=0;i<N;i++){
		if(max_hand_win<max[i]){
			max_hand_win=max[i];
			max_hand=i;
		}
	}
	max_hand++;
	out_hand=max_hand;
	
	for(int i=0;i<1000;i++){
		cout<<out_hand<<endl;
		cin>>ai_hand;
		fflush(stdout);
		
	}
}