#include<iostream>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        sum+=x;
    }
    ll ans=(n*(n+1))/2;
    cout<<ans-sum<<endl;
    return 0;
    

}