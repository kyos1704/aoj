#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	int s[1010];
	double m;
	while(cin>>n,n!=0){
		m=0;
		for(int i=0;i<n;i++){
			cin>>s[i];
			m+=s[i];
		}
		m/=n;
		double ans=0;
		
		for(int i=0;i<n;i++){
			ans+=(double(s[i]-m)*(s[i]-m))/n;
		}
		ans=sqrt(ans);
		
		cout.setf(ios::fixed,ios::floatfield);
		cout<<ans<<endl;
		
	}
}
