#include<iostream>
#include<cstdio>
using namespace std;


int main(){
	int n,m;
	while(scanf("%d %d",&n,&m),(n!=0)||(m!=0)){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if((i+j)%2==0){
					cout<<"#";
				}else{
					cout<<".";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
}


