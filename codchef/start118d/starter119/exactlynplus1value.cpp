
//https://www.codechef.com/practice/course/2-star-difficulty-problems/DIFF1500/problems/N1VALUES

#define ll long long int
#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<"1"<<" ";
        for(ll i=0;i<n;i++)
        cout<<(1LL<<i)<<" ";
        cout<<endl;
    }
}
