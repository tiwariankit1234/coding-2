//https://www.codechef.com/problems/CHEFIZZA?tab=statement
#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
	cin>>t;
	while(t--)
	{
	    int x;
	    cin>>x;
	    int count=2;
	    while(count<=x){
	        count=count*2;
	    }
	    int diff=count-x;
	    cout<<x-diff<<endl;
	}
	
}
// ek circle ke kitne tuke baaki tukde se bade hain
 even power me count karenge
 jitne maange x piece unko subtract karenge even power se then diff ko subtract karenge actual se