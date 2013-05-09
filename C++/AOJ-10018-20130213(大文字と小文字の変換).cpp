#include<iostream>
#include<cstdio>
using namespace std;
 
int main(){
    string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(islower(s[i])){
			s[i]=toupper(s[i]);
		}else if(isupper(s[i])){
			s[i]=tolower(s[i]);
		}
	}
	cout<<s<<endl;
    return 0;
}