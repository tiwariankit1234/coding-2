#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n, q;
	    cin>>n>>q;
	    
	    vector<int> a(n);
	    for(auto &e: a)
	        cin>>e;
	        
        map<int, int> poss;
        map<int, pair<int, int>> ind;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                ind[a[i] + a[j]] = {i, j};
                poss[a[i] + a[j]] = 1;
            }
        }
        
        int tot = accumulate(a.begin(), a.end(), 0);
        
        while(q--)
        {
            int x;
            cin>>x;
            
            if(poss[2*tot-x])
            {
                cout<<a[ind[2*tot-x].first]<<" ";
                for(int i=0; i<n; i++)
                {
                    if(i==ind[2*tot-x].first || i==ind[2*tot-x].second)
                        continue;
                        
                    cout<<a[i]<<" ";
                }
                
                cout<<a[ind[2*tot-x].second]<<"\n";
            }
            else
                cout<<"-1\n";
        }
	}
}