#include<iostream>
#include <algorithm>
#include<functional>//greater‚ÌŽg—p
using namespace std;
#define MAX_LIST 60000


bool find_list(int *list,int a,int b,int x){
	//cout<<list[a]<<" "<<list[b]<<" "<<list[(b+a)/2]<<" "<<x<<endl;
	if(b-a<2){
		if(list[b]==x){
			//cout<<"find"<<endl;
			return true;
		}
		if(find(list+a,list+b,x)!=list+b){
			//cout<<"find"<<endl;
			return true;
		}
		//cout<<"false"<<endl;
		return false;
	}
	if(list[(b+a)/2]>x){
		return find_list(list,a,(b+a)/2,x);
	}else if(list[(a+b)/2]<x){
		return find_list(list,(a+b)/2,b,x);
	}
	//cout<<"find "<<list[(b+a)/2]<<" "<<x<<endl;
	return true;
}

int main(){
	bool prime[MAX_LIST];
	for(int i=0;i<MAX_LIST;i++){
		prime[i]=1;
	}
	prime[0]=prime[1]=0;
	for(int i=0;i*i<MAX_LIST;i++){
		if(prime[i]==1){
			for(int j=i*2;j<MAX_LIST;j=j+i){
				prime[j]=0;
			}
		}
	}
	int primelist[60000];
	int j=0;
	for(int i=0;i<MAX_LIST;i++){
		if(prime[i]==1){
			primelist[j]=i;
			j++;
			if(j>60000){
				break;
			}
		}
	}
	int in;
	while(cin>>in,in){
		int ans=0;
		int t=0;
		int r;
		while(in>primelist[t])t++;
		if(in%2==1){
			r=2;
		}else{
			r=t;
		}
		for(int i=0;i<r;i++){
			if(find_list(primelist,i,t,in-primelist[i])){
			ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
