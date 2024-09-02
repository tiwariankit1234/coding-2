#include <bits/stdc++.h>
using namespace std;

#define ll long long // Correctly defining ll as long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll sum=0;
        // Your logic for finding k is correct
        ll k;
        if (n % 2 != 0) {
        
         ll x=n/2;
           cout<<(x*(x+1))+(n+1)/2<<endl;
            
            // 2*(1+2)+(3)
        
        } else {
           ll x=n/2;
            cout<<(x*(x+1))<<endl;
           // 2*(1+2)
         
        } 
    }
    return 0;
}
// //www.codechef.com/problems/MINANDMAX?tab=statement
