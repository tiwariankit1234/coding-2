class Solution {
public:
    string repeatLimitedString(string s, int x) {
        int n=s.size();
        unordered_map<char,int>mp;
        string t="";
        for(char c:s){
            mp[c]++;
        }
        priority_queue<pair<char,int>>pq(mp.begin(),mp.end());
        while(pq.size()>0){
            auto [newchar,freq]=pq.top();
            // cout<<newchar<<" "<<freq<<endl;
            pq.pop();
            int k=min(freq,x);
            t.append(k,newchar);
           freq-=k;
           if(freq>0 and pq.size()){
           auto[nextchar,freq1]=pq.top();
             pq.pop();
                t.push_back(nextchar);
                freq1--;
                if(freq1>0)   pq.push({nextchar,freq1});
              pq.push({newchar,freq});
           }

        }
        return t;
       

    }
};