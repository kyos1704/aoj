#include <iostream>
#include <stack>
#include <string>
using namespace std;



int main(){
	stack<char> st[101];
	
	int n,p;
	char b;
	cin>>n;
	string s;
	
	while(1){
		cin>>s;
		if(s=="quit"){
			break;
		}else if(s=="push"){
			cin>>p;
			cin>>b;
			st[p].push(b);
		}else if(s=="pop"){
			cin>>p;
			cout<<st[p].top()<<endl;
			st[p].pop();
		}else if(s=="move"){
			cin>>p;
			b=st[p].top();st[p].pop();
			cin>>p;
			st[p].push(b);
		}else {
			cout<<"undifined"<<endl;
			break;
		}
	}
	
	
}