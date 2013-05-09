#include<iostream>
#include<cstdio>
using namespace std;
 
int main(){
    string s;
	while(cin>>s,s!="0"){
		int ans=0;
		for(int i=0;i<s.size();i++){
			ans+=s[i]-'0';
		}
		cout<<ans<<endl;
	}
    return 0;
}