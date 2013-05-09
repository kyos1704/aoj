#include<iostream>
#include<cstdlib>
using namespace std;

int num[50]={0};


int main(){
	int n,p;
	while(cin>>n>>p,n!=0||p!=0){
		int fin=p;
		for(int i=0;i<50;i++){
			num[i]=0;
		}
		
		int i=100;
		while(1){
			i++;
			if(i>=n){
				i=0;
			}
			if(p>0){
				num[i]++;
				p--;
			}else if(p==0){
				p+=num[i];
				num[i]=0;
			}else{
				cout<<"hoge"<<endl;
			}
			if(num[i]==fin){
				break;
			}
		}
		cout<<i<<endl;
	}
	return 0;
}