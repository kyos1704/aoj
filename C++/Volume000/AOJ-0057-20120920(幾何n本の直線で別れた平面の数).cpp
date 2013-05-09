#include<iostream>
using namespace std;
int ans(int a){
	if(a==1) return 2;
	return a+ans(a-1);
}
int main(){
	int n;
	while(cin>>n){
		cout<<ans(n)<<endl;
	}
	return 0;
}
