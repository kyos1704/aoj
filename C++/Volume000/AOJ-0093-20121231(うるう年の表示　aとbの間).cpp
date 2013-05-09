#include<iostream>
using namespace std;

int main(){
	int a;
	int b;
	bool first=true;
	
	while(cin>>a>>b,a*b){
		if(first!=true){
			cout<<endl;
		}else{
			first=false;
		}
		bool j=false;
		for(int i=a;i<b+1;i++){
			if(i%4==0){
				if(i%400==0){
					j=true;
					cout<<i<<endl;
				}else if(i%100==0){
				}else{
					j=true;
					cout<<i<<endl;
				}
			}else{
			}
		}
		if(j==false)cout<<"NA"<<endl;
	}
	return 0;
}