#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int n;
	int max,min;
	char in[9];
	cin>>n;
	while(n--){
		cin >>in;
		max=min=0;
		for(int i=0;i<8;i++){
			in[i]=in[i]-'0';
		}
		sort(in,in+8);
		for(int i=0;i<8;i++){
			max=max+in[i]*pow(10,i);
			min=min+in[i]*pow(10,7-i);
		}
		cout<<max-min<<endl;
	}
	return 0;
	
}
