#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

char s[15][15];

char solve(int i,int j){
	if(s[i][j]=='1'&&s[i+1][j]=='1'&&s[i][j+1]=='1'&&s[i+1][j+1]=='1'){
		return 'A';
	}
	if(s[i][j]=='1'&&s[i+1][j]=='1'&&s[i+2][j]=='1'&&s[i+3][j]=='1'){
		return 'B';
	}
	if(s[i][j]=='1'&&s[i][j+1]=='1'&&s[i][j+2]=='1'&&s[i][j+3]=='1'){
		return 'C';
	}
	if(s[i][j]=='1'&&s[i][j+1]=='1'&&s[i+1][j+1]=='1'&&s[i+1][j+2]=='1'){
		return 'E';
	}
	if(s[i][j]=='1'&&s[i+1][j]=='1'&&s[i+1][j+1]=='1'&&s[i+2][j+1]=='1'){
		return 'F';
	}
	if(j>0){
		if(s[i][j]=='1'&&s[i+1][j]=='1'&&s[i+1][j-1]=='1'&&s[i+2][j-1]=='1'){
			return 'D';
		}
		if(s[i][j]=='1'&&s[i+1][j]=='1'&&s[i+1][j-1]=='1'&&s[i][j+1]=='1'){
			return 'G';
		}
	}
	return 0;
}


int main(){

	
	
	while(!cin.eof()){
		
		for(int i=0;i<15;i++){
			for(int j=0;j<15;j++){
				s[i][j]='0';
			}
		}
		for(int i=0;i<8;i++){
			cin>>s[i];
		}
		char ans;
		bool solved=true;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(s[i][j]!='1')continue;
				if(solved){
					ans=solve(i,j);
					cout<<ans<<endl;
					solved=false;
				}
			}
		}
	}
	
	
	return 0;
}