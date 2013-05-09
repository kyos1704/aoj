#include<iostream>
#include<cstdio>
using namespace std;

int c_int(char a){
	if(a=='S'){
		return 0;
	}else if(a=='H'){
		return 1;
	}else if(a=='C'){
		return 2;
	}else if(a=='D'){
		return 3;
	}
}

char i_char(int a){
	if(a==0){
		return 'S';
	}else if(a==1){
		return 'H';
	}else if(a==2){
		return 'C';
	}else if(a==3){
		return 'D';
	}
}

int main(){
	int N;
	cin>>N;
	char c;
	int n;
	bool cards[4][13]={0};
	for(int i=0;i<N;i++){
		cin>>c;
		cin>>n;
		cards[c_int(c)][n-1]=1;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(cards[i][j]!=1){
				cout<<i_char(i)<<" "<<j+1<<endl;
			}
		}
	}
}


