#include<iostream>
using namespace std;

bool solve(int r,int c){
	if(r%2==1 && c%2 ==1){
		return false;
	}else{
		return true;
	}
}


int main(){
	int r,c;
	
	while(cin>>r>>c,r!=0||c!=0){
		if(solve(r,c)){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
}