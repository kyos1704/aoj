#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define INF 100000



int main(){
	int w;
	bool ans[10];
	for(int i=0;i<11;i++){
		ans[i]=0;
	}
	while(cin>>w){
		
		for(int i=0;i<11;i++){
			ans[i]=0;
		}
		for(int i=10;i--;){
			if(w>=pow(2,i)){
				ans[i]=1;
				w=w-pow(2,i);
			}
		}
		
		int i=0;
		for(;i<11;i++){
			if(ans[i]){
				cout<<pow(2,i);
				break;
			}
		}i++;
		for(;i<11;i++){
			if(ans[i]){
				cout<<" "<<pow(2,i);
			}
		}cout<<endl;
	}
	return 0;
}