#include<iostream>
#include<string>
using namespace std;
 
int main(){
	string s;
	int num[26]={0};
	while(getline(cin,s)){
		for(int i=0;i<s.size();i++){
			if(s[i]!=' '){
				if(isupper(s[i])){
					s[i]=tolower(s[i]);
				}
				num[s[i]-'a']++;
			}
		}
	}
	for(int i=0;i<26;i++){
		cout<<char('a'+i)<<" : "<<num[i]<<endl;
	}
    return 0;
}