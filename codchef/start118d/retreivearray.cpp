#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,sum=0;
	    cin>>n;
	    vector<int>v(n);
	    for(int i=0;i<v.size();i++){
	        cin>>v[i];
	        sum+=v[i];
	    }
	    vector<int>arr(n);
	    int arrsum=sum/(n+1);
	    for(int i=0;i<n;i++)
	    {
	        int x=v[i]-arrsum;
	         cout<<x<<" ";
	    
	    }
	    cout<<endl;
	}
return 0;
}
