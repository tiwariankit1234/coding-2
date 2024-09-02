//1649B
#include <bits/stdc++.h>
#define fo(i,n) for(int i=0; i<n; i++)
#define fi(i,n) for(int i=n-1; i>=0; i--)
#define rep(i,k,n) for(int i=k; i<n; i++)
#define rrep(i,x,y) for(int i=x; i>=y; i--)
#define yes cout << "YES\n" ;
#define no cout << "NO\n";
#define pii pair <int,int> 
#define vi vector <int>
#define all(a) a.begin(),a.end() 
using namespace std;
#define int long long
#define ll long long
const long long MOD=998244353;

void solve(){

    ll n,m=1,k=1,x=0, y=0;
    cin >> n;
    
    while(m<=n) m*=2;
    m/=2;
    cout << n-m << ' ' << m << '\n';
}
signed main(){
    ll t=1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

// two numbers having difference very less and having xor equal to x