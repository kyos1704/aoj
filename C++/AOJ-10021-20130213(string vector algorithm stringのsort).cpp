#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(){
	string s;
	vector<string> str_list;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		str_list.push_back(s);
	}
	sort(str_list.begin(),str_list.end());
	cout<<str_list[0]<<endl;
    return 0;
}