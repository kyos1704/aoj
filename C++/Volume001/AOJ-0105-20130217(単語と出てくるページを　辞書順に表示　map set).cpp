#include<iostream>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int main(){
	map<string,set<int> > data;
	string tmpWord;
	int tmpPage;
	while(cin>>tmpWord>>tmpPage){
		data[tmpWord].insert(tmpPage);
	}
	for(map<string,set<int> >::iterator i=data.begin();i!=data.end();i++){
		cout<<(i->first)<<endl;
		for(set<int>::iterator j=(i->second).begin();j!=(i->second).end();j++){
			if(j!=(i->second).begin())cout<<" ";
			cout<<*j;
		}
		cout<<endl;
	}
}