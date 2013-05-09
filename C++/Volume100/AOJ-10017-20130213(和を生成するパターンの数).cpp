#include<iostream>
#include<cstdio>
using namespace std;
 
int main(){
    int n,x;
     
    while(scanf("%d %d",&n,&x),(x!=0)||(n!=0)){
        int ans=0;
        for(int i=1;i<n+1;i++){
            for(int j=i+1;j<n+1;j++){
                for(int k=j+1;k<n+1;k++){
                    if(i+j+k==x){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}