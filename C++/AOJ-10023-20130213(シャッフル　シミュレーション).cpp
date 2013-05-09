#include<iostream>
#include<string>
using namespace std;



int main(){
	string s;
	int m,h;
	int front_pos;
	while(cin>>s,s!="-"){
		cin>>m;
		front_pos=0;
		for(int i=0;i<m;i++){
			cin>>h;
			front_pos+=h;
		}
		front_pos%=s.size();
		for(int i=front_pos;i<s.size();i++){
			cout<<s[i];
		}
		for(int i=0;i<front_pos;i++){
			cout<<s[i];
		}
		cout<<endl;
	}
    return 0;
}