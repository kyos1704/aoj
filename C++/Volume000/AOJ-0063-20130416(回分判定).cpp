#include<iostream>
#include<string>
using namespace std;


bool rev(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]!=(s[s.size()-1-i])){
			return 0;
		}
	}
	return 1;
}

int main(){
	string s;
	int ans=0;
	while(cin>>s){
		if(rev(s)){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}