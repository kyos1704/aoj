#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string in[1000];
	int max=0;
	string ml_str;
	int tmp;
	string ans;
	int i=0;
	for(i=0;cin>>in[i];i++){
		if(in[i].size()>max){
			max=in[i].size();
			ml_str=in[i];
		}
	}
	sort(in,in+i);
	tmp=1;
	max=0;
	for(int j=1;j<i;j++){
		if(in[j]==in[j-1]){
			tmp++;
		}else{
			if(max<tmp){
				max=tmp;
				ans=in[j-1];
				tmp=1;
			}
		}
	}
	cout<<ans<<" "<<ml_str<<endl;
}
