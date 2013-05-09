#include<iostream>
using namespace std;

int main(){
	int n;
	string a[2];
	int ans[2]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[0]>>a[1];
		if(a[0]<a[1]){
			ans[1]+=3;
		}else if(a[1]<a[0]){
			ans[0]+=3;
		}else {
			ans[0]++;
			ans[1]++;
		}
	}
	cout<<ans[0]<<" "<<ans[1]<<endl;
}
