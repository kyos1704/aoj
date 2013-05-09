#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	
	while(cin>>n,n!=0){
		vector<int> list;
		int ans=0;
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			list.push_back(tmp);
		}
		sort(list.begin(),list.end());
		for(int i=1;i<n-1;i++){
			ans+=list[i];
		}
		ans/=(n-2);
		
		cout<<ans<<endl;
	}
}