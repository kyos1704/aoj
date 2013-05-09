#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 110
int main(){
	stack<char> s;
	string n;
	char a;
	while((cin>>n),n!="quit"){
		if(n=="push"){
			cin>>a;
			s.push(a);
		}else if(n=="pop"){
			cout<<s.top()<<endl;s.pop();
		}
	}
	
	
	
	return 0;
}