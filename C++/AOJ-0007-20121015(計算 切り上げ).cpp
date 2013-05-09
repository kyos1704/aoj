#include<iostream>
using namespace std;
#define RENT 100000
int main(){
	int n;
	while(cin>>n){
		int ans;
		ans=RENT;
		for(int i=0;i<n;i++){
			ans=ans*1.05;
			if(ans%1000>0){
				ans=ans+1000-ans%1000;
			}
		}
		
		
		cout<<ans<<endl;
	}
}