#include<iostream>
using namespace std;
int main(){
	int ans,w;
	while(cin>>w,w!=-1){
		ans=1150;
		if(w>30){
			ans+=160*(w-30);
			w=30;
		}
		if(w>20){
			ans+=140*(w-20);
			w=20;
		}
		if(w>10){
			ans+=125*(w-10);
		}
		cout<<4280-ans<<endl;
	}
}