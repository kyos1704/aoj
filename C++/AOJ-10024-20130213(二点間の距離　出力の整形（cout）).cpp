#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long double a,b,c,d;
	cin>>a>>b>>c>>d;
	long double tmp=(a-c)*(a-c)+(b-d)*(b-d);
	tmp = sqrt(tmp);
	cout.setf(ios::fixed,ios::floatfield);
	cout<<tmp<<endl;
	
}