#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<2){
            cout<<"YES"<<endl;
            continue;
        }
        vector<int>v(n);
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        bool possible = true;
      for(int i=0;i<2;i++){
        s.insert(v[i]);
      }
      for(int i=2;i<n;i++){
        if(s.count(v[i]-1)||s.count(v[i]+1))
      {
        s.insert(v[i]);
      }
        else{
            possible=false;
         
            break;
        }
      }
   if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}

