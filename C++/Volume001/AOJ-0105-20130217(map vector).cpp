#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;



int main(){
	map<string,vector< int > > data;
	vector<string> words;
	string tmpWord;
	int tmpPage;
	while(cin>>tmpWord>>tmpPage){
		words.push_back(tmpWord);
		data[tmpWord].push_back(tmpPage);
	}
	int s=words.size();
	sort(words.begin(),words.end());
	for(int i=0;i<s;i++){
		if(i!=0)if(words[i]==words[i-1])continue;
		cout<<words[i]<<endl;
		sort(data[words[i]].begin(),data[words[i]].end());
		int si=data[words[i]].size();
		for(int j=0;j<si;j++){
			if(j!=0)cout<<" ";
			cout<<data[words[i]][j];
		}
		cout<<endl;
	}
}