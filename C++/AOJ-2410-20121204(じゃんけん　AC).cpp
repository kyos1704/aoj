#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;

 
int main(){
	srand(unsigned(time(NULL)));
	char judge[20][20];
	int N;
	int ai_hand;
	int max[20];
	int max_hand_win=0;
	int out_hand;
	int max_hand;
	int ave_max=0;
	bool ave[20];
	for(int i=0;i<20;i++){
		ave[i]=0;
	}
	int out_hands[20];
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
		ave_max+=max[i];
		if(max_hand_win<max[i]){
			max_hand_win=max[i];
			max_hand=i;
		}
	}
	
	ave_max=ave_max/N;
	
	////
	ave_max=max_hand_win-15;
	
	////
	
	for(int i=0;i<N;i++){
		if(max[i]>ave_max){
			ave[i]=1;
		}
	}
	int count=0;
	for(int i=0;i<N;i++){
		if(ave[i]==1){
			out_hands[count]=i;
			count++;
		}
	}
	if(count==0){
		out_hands[0]=max_hand;
		count++;
	}
	
	
	for(int i=0;i<1000;i++){
		
		cout<<out_hands[rand()%count]+1<<endl;
		cin>>ai_hand;
		fflush(stdout);
		
	}
}