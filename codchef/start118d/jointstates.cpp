#include <bits/stdc++.h>
using namespace std;

int main() {
	 int t;
    cin >> t;

    while (t--) {
        int p, q, r;
        cin >> p >> q ;
        vector<int> v(p); // Change to p as the size of the vector

        long long sum = 0;

        for (int i = 0; i < p; i++) { // Use p as the limit for iteration
            cin >> v[i];
          
        }

        int count = 0;
        for (int i = 0; i<v.size(); i++) {
            if (v[i]>=q) {
                 // Fix the sum calculation here
                sum=0;
                count++;
              
            } else if(v[i]<q){
                sum+=v[i];
                if(sum>=q)
              {  count++;
              sum=0;
            }
                
            
        }
        }
        cout<<count<<endl;
    }
    return 0;

}
