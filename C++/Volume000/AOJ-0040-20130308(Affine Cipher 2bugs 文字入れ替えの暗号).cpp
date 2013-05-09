#include<iostream>
#include<string>
using namespace std;

int trans[26];


void makelist(int a,int b){
	for(int i=0;i<26;i++){
		trans[i]=(a*i+b)%26;
	}
}

string translate(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]>='a' && s[i]<='z'){
			s[i]=trans[s[i]-'a']+'a';
		}
	}
	return s;
}

int main(){
	//a!=2,13 **
	int n;
	cin>>n;
	cin.ignore();
	for(int count=0;count<n;count++){
		string s;
		getline(cin,s);
		string tmp=s;
		int a=0,b=100;
		while(s.find("that")==string::npos && s.find("this")== string::npos){
			b++;
			if(b>=26){
				b=0;
				a++;
			}
			
			while(a%2==0||a%13==0)a++;
			makelist(a,b);
			s=translate(tmp);
			//cout<<s<<endl;
		}
		cout<<s<<endl;
	}
}