#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	char s[1000];
	cin.getline(s,sizeof(s));
	for(int i=0;s[i]!='\0';i++){
		if((s[i]!=' ')&&(s[i]!='.')){
			putchar(s[i]-'a'+'A');
		}else{
			putchar(s[i]);
		}
	}cout<<endl;
	return 0;
}
