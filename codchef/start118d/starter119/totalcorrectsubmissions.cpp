//https://www.codechef.com/practice/course/2-star-difficulty-problems/DIFF1500/problems/TOTCRT?tab=statement
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        int n;
        cin>>n;
        int k=n*3;
        int t;
        unordered_map<string,int>mp;
        for(int i=0;i<k;i++){
            cin>>s>>t;
            mp[s]+=t;
        }
        vector<int>ans;
        for(auto[x,y]:mp){
            ans.push_back(y);
        }
        sort(ans.begin(),ans.end());
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
    
        
    }

}
