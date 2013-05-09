#include<iostream>
#include<cmath>
using namespace std;




int main(){
	double a,b,c;
	cin>>a>>b>>c;
	double s,l,h;
	c=c*M_PI/180;
	s=a*b*sin(c)/2;
	l=sqrt(a*a+b*b-2*a*b*cos(c))+a+b;
	h=(s*2)/a;
	
	
	
	cout.setf(ios::fixed,ios::floatfield);
	cout<<s<<endl;
	cout<<l<<endl;
	cout<<h<<endl;
	
}
