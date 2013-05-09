#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int> ans,tmp,tmp2;
	int n,r;
	while(cin>>n>>r,n||r){
		for(int i=0;i<n;i++){
			ans.push(n-i);
		}
		int p,c;
		for(int i=0;i<r;i++){
			cin>>p>>c;
			for(int j=0;j<n;j++){
				if(j<p-1){
					tmp.push(ans.front());ans.pop();
				}else if(j<p+c-1){ 
					tmp2.push(ans.front());ans.pop();
				}else{
					tmp.push(ans.front());ans.pop();
				}
			}
			while(tmp2.empty()!=true){
				ans.push(tmp2.front());tmp2.pop();
			}
			while(tmp.empty()!=true){
				ans.push(tmp.front());tmp.pop();
			}
		}
		cout<<ans.front()<<endl;
		while(ans.empty()!=true){
			ans.pop();
		}
	}
	return 0;
}