#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define INF 100000



int main(){
	int b,c;
	int a;
	int n;
	bool ans;
	cin>>n;
	while(n--){
		ans=true;
		b=c=0;
		for(int i=0;i<10;i++){
			cin>>a;
			if(a>b){
				b=a;
			}else if(a>c){
				c=a;
			}else{
				ans=false;
			}
		}
		if(ans){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}