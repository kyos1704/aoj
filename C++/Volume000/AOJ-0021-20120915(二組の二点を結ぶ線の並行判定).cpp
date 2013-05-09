#include<iostream>
using namespace std;

int main(){
	int n;
	double x[4],y[4];
	cin>>n;
	for(;n--;){
		for(int i=0;i<4;i++){
			cin>>x[i];
			cin>>y[i];
		}
		if((x[0]-x[1])*(y[2]-y[3])-(x[2]-x[3])*(y[0]-y[1])==0){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
  