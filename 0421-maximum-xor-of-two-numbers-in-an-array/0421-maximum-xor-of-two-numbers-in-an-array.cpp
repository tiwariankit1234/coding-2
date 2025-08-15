
struct TrieNode{
    TrieNode* next[2];
    TrieNode(){
        next[0]=nullptr;
        next[1]=nullptr;
    }
};




class Solution {
public:
TrieNode *root=new TrieNode();
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
int findMaxXor(int num){
    TrieNode* node=root;
    int maxor=0;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        int opposite=1-bit;
        if(node->next[opposite]){
            maxor|=(1<<i);
            node=node->next[opposite];
        }
        else{
            node=node->next[bit];
        }
    }
    return maxor;
}
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        for(int num:nums){
            insert(num);
        }
        int maxresult=0;
        for(int num:nums){
            maxresult=max(maxresult,findMaxXor(num));
        }
        return maxresult;

    }
};