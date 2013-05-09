#include<iostream>
using namespace std;
int f(int x){
	if(x>3){
		x++;
	}
	if(x>5){
		x++;
	}
	return x;
}
int main(){
	int n;
	int ans[20];
	int count;
	while(cin>>n,n){
		count=0;
		for(int i=0;n>0;i++){
			ans[i]=(n%8);
			n=n/8;
			count++;
		}
		while(count--){
			cout<<f(ans[count]);
		}cout<<endl;
	}
	return 0;
}