#include<iostream>
using namespace std;
#define MAX 110
int main(){
	int m,f,r;
	while((cin>>m>>f>>r),(m!=-1)||(f!=-1)||(r!=-1)){
		if(f==-1 || m==-1){
			cout<<"F"<<endl;
		}else if(m+f>79){
			cout<<"A"<<endl;
		}else if(m+f>64){
			cout<<"B"<<endl;
		}else if(m+f>49){
			cout<<"C"<<endl;
		}else if(m+f>29){
			if(r>49){
				cout<<"C"<<endl;
			}else{
				cout<<"D"<<endl;
			}
		}else{
			cout<<"F"<<endl;
		}
	}
	return 0;
}