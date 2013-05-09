#include<iostream>
using namespace std;

int main(){
	int y,m,d;
	
	while(cin>>y){
		cin>>m;
		cin>>d;
		if(y>1989||(y==1989&&((m>1)||(d>7)))){
			cout<<"heisei "<<y-1988<<" "<<m<<" "<<d<<endl;
		}else if(y>1926||(y==1926&&(m==12&&d>24))){
			cout<<"showa "<<y-1925<<" "<<m<<" "<<d<<endl;
		}else if(y>1912||(y==1912&&(m>7||d>29))){
			cout<<"taisho "<<y-1911<<" "<<m<<" "<<d<<endl;
		}else if(y>1868||(y==1868&&(m>9||d>7))){
			cout<<"meiji "<<y-1867<<" "<<m<<" "<<d<<endl;
		}else{
			cout<<"pre-meiji"<<endl;
		}
	}
	return 0;
	
}
