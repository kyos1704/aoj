#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;


int main(){
	string tmp[200];
	string out="aaaa";
	string s;
	int count=0;
	while(1){
		cout<<"?"<<out<<endl;
		tmp[count]=out;
		count++;
		
		cin>>s;
		if(s[0]!=out[3]){
			cout<<"!OUT"<<endl;
			return 0;
		}
		for(int i=0;i<count;i++){
			if(tmp[i]==s){
				cout<<"!OUT"<<endl;
				return 0;
			}
		}
		tmp[count]=s;
		count++;
		
		
		out[0]=s[s.size()-1];
		if(out[1]!='z'){
			out[1]++;
		}else{
			out[2]++;
		}
		
		
	}
}