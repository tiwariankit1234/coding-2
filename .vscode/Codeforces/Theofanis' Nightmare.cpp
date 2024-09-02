#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        long long suf[n+1] = {0};
        for(int i = 0;i < n;i++){
            cin>>arr[i];
        }
        for(int i = n-1;i >= 0;i--){
            suf[i] = suf[i+1] + arr[i];
        }
        long long ans = suf[0];
        for(int i = 1;i < n;i++){
            if(suf[i] > 0){
                ans += suf[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}