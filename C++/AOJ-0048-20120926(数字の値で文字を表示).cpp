#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	double n;
	while(cin>>n){
		if(n>91){
			cout<<"heavy"<<endl;
		}else if(n>81){
			cout<<"light heavy"<<endl;
		}else if(n>75){
			cout<<"middle"<<endl;
		}else if(n>69){
			cout<<"light middle"<<endl;
		}else if(n>64){
			cout<<"welter"<<endl;
		}else if(n>60){
			cout<<"light welter"<<endl;
		}else if(n>57){
			cout<<"light"<<endl;
		}else if(n>54){
			cout<<"feather"<<endl;
		}else if(n>51){
			cout<<"bantam"<<endl;
		}else if(n>48){
			cout<<"fly"<<endl;
		}else{
			cout<<"light fly"<<endl;
		}
	}
}
