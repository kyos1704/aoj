#include<iostream>
#include<string>
using namespace std;

int main(){
	char pos='A';
	string in;
	while(cin>>in){
		if(in[0]==pos){
			pos=in[2];
		}else if(in[2]==pos){
			pos=in[0];
		}
	}
	cout<<pos<<endl;
}