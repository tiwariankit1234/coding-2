class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxsum) {
        unordered_set<int>s(banned.begin(),banned.end());
          int count=0;
        for(int i=1;i<=n;i++){
            if(s.contains(i))continue;
            
            if(maxsum-i<0)return count;

            maxsum-=i;
            count++;
        }
        return count;
    }
};