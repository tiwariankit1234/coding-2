//                      जय श्रीराम
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ld long double
#define for0(n) for (ll i = 0; i < n; i++)
#define for1(n) for (ll i = 1; i <= n; i++)
#define fors(n) for (ll i = 0; i < n - 1; i++)
#define cl1(n) cout << n << endl;
#define cl2(n) cout << "n" << endl;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
//#define umap(i) unordered_map<int,int>f1;
//#define umap(c) #unordered_map<char,int>f2;
#define formap1 for (auto x : f1)
#define S second
#define F first
#define pb push_back
#define ppb pop_back
#define in insert
#define bg begin()
#define end end()
#define fr(j, s) for (auto j : s)
ll gcd(ll a, ll b) // pass max 1st and the min
{
  if (a == 0 || b == 0)
    return 0;
  if ((a % b) == 0)
    return b;
  else
    return gcd(b, a % b);
}
void solve() { std::ios_base::sync_with_stdio(false); 
    ll n,k;
    cin>>n>>k;
    if(k<n*(n+1)/2) cout<<-1<<endl;
    else 
    {
        for0(n-1) cout<<1<<" ";
        cout<<k-((n*(n+1)/2))+1;
        cout<<endl;
    }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  long long int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}