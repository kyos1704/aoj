#include<iostream>
#include<sstream>
#include<string>
using namespace std;



bool rev(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			return false;
		}
	}
	return true;
}


bool solve(int n,int i){
	stringstream ss1,ss2;
	string tmp;
	ss1<<n-i;
	ss1>>tmp;
	if(rev(tmp)){
		cout<<tmp<<endl;
		return 1;
	}
	ss2<<n+i;
	ss2>>tmp;
	if(rev(tmp)){
		cout<<tmp<<endl;
		return 1;
	}
	return 0;
}


int main(){
	int n;
	cin>>n;
	for(int i=0;1;i++){
		if(solve(n,i)){
			break;
		}
	}
	return 0;
}