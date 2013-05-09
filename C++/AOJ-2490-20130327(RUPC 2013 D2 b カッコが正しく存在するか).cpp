#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int count=0;
	bool j=true;
	for(int i=0;i<n;i++){
		char c;
		int num;
		cin>>c>>num;
		if(c=='('){
			count+=num;
		}else{
			count-=num;
			if(count<0){
				j=false;
			}
		}
	}
	if(j&&count==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}