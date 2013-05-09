#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> hoge;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		hoge.push_back(tmp);
	}
	sort(hoge.begin(),hoge.end());
	for(int i=0;i<n-1;i++){
		cout<<hoge[i]<<" ";
	}cout<<hoge[n-1]<<endl;
}
