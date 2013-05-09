#include<iostream>
#include<algorithm>
using namespace std;
 
 
bool serch(int* list,int min,int max,int x){
    //cout<<min<<" "<<max<<" "<<x<<endl;
    int med=(min+max)/2;
    if(list[med]==x)return 1;
    if((min<max)!=true)return 0;
    if(list[med]<x){
        if(serch(list,med+1,max,x)){
            return 1;
        }
        return 0;
    }else if(list[med]>x){
        if(serch(list,min,med-1,x)){
            return 1;
        }
        return 0;
    }
    return 0;
}
 
int main(){
    int list[100010];
    int n;
    int q,in;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    sort(list,list+n);
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>in;
        if(serch(list,0,n-1,in)){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}