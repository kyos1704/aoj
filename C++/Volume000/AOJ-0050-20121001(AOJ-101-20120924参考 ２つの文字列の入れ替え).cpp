#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	string s;
	int c_num[2];
	int c_pos[2][1000];
	string c[2];
	c[1]="apple";
	c[0]="peach";
	getline(cin,s);
	for(c_num[0]=0;(c_num[0]<1000)&&((c_pos[0][c_num[0]]=s.find("apple"))!=string::npos);c_num[0]++){
		s.replace(c_pos[0][c_num[0]],5,"aaaaa");
	}
	for(c_num[1]=0;(c_num[1]<1000)&&((c_pos[1][c_num[1]]=s.find("peach"))!=string::npos);c_num[1]++){
		s.replace(c_pos[1][c_num[1]],5,"aaaaa");
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<c_num[i];j++){
			s.replace(c_pos[i][j],5,c[i]);
		}
	}
	cout<<s<<endl;
}
