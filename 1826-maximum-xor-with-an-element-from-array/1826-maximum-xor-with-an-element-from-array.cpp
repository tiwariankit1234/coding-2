class TrieNode{
    public:
    TrieNode *next[2];
    TrieNode(){
        next[0]=nullptr;
        next[1]=nullptr;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(int num){
         TrieNode* node=root;
         for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->next[bit]){
                node->next[bit]=new TrieNode();
            }
            node=node->next[bit];
         }
    }
    int getMaxXor(int num){
        TrieNode* node=root;
        int maxor=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int oppositebit=1-bit;
            if(node->next[oppositebit]){
                maxor|=(1<<i);
                node=node->next[oppositebit];
            }
            else{
                node=node->next[bit];
            }
        }
        return maxor;
    }
};



class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        sort(nums.begin(),nums.end());
        vector<array<int,3>>q;
        for(int i=0;i<n;i++){
            q.push_back({queries[i][0],queries[i][1],i});
        }
        sort(q.begin(),q.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        vector<int>ans(n,-1);
        Trie trie;
        int idx=0;
        for(auto &query:q){
            int x=query[0],m=query[1],qidx=query[2];
            while(idx<nums.size() and nums[idx]<=m){
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx>0){
                ans[qidx]=trie.getMaxXor(x);
            }
        }
        return ans;

    }
};