#include<iostream>
#include<string>
using namespace std;

string lower(string s){
	for(int i=0;i<s.size();i++){
		s[i]=tolower(s[i]);
	}
	return s;
}



int main(){
	string s,n;
	int ans=0;
	cin>>s;
	s=lower(s);
	while(cin>>n,n!="END_OF_TEXT"){
		n=lower(n);
		if(s==n){
			ans++;
		}
	}
	cout<<ans<<endl;
    return 0;
}