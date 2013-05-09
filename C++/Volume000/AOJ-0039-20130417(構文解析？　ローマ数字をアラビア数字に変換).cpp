#include<iostream>
#include<string>
#include<vector>
using namespace std;

string index="IVXLCDM";
int trans[]={1,5,10,50,100,500,1000};

int t_num(char c){
	for(int i=0;i<index.size();i++){
		if(c==index[i]){
			return trans[i];
		}
	}
}

int main(){
	string input;
	while(cin>>input){
		int ans=0;
		vector<int> in;
		for(int i=0;i<input.size();i++){
			in.push_back(t_num(input[i]));
		}
		int tmp=0;
		tmp=in[0];
		for(int i=1;i<in.size();i++){
			if(in[i]>in[i-1]){
				tmp=in[i]-tmp;
			}else if(in[i]<in[i-1]){
				ans+=tmp;
				tmp=in[i];
			}else{
				tmp+=in[i];
			}
		}
		ans+=tmp;
		cout<<ans<<endl;
		
	}
	return 0;
}