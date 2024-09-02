#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int>v(n+1);
 
    for(int i=1;i<=n;i++)
    {
        
        cin>>v[i];
    }
    v[0]=5000;
    sort(v.begin()+1,v.end());
    
    cout<<endl;
    int ans=0;
    int curr=1;
    for(int i=1;i<=n;i++){
        if(v[i]>i){
        ans=-1;
        break;
        }
        ans+=(i-v[i]);
        
        
        
    }
   cout<<ans<<endl;;
}
return 0;

}
