class TrieNode{
    public:
    bool isFlag;
    vector<TrieNode*>v;
    TrieNode(){
        isFlag=false;
        v.resize(26,NULL);
    }
};

class Trie {
public:
TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        int n=word.size();
        TrieNode* node=root;
        for(int i=0;i<n;i++){
          if(!node->v[word[i]-'a']){
            node->v[word[i]-'a']=new TrieNode();
          }
          node=node->v[word[i]-'a'];
        }
        node->isFlag=true;
        return ;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->v[word[i]-'a']){
              return false;
            }
            node=node->v[word[i]-'a'];
        }
         return node->isFlag;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        TrieNode* node=root;
        for(int i=0;i<n;i++){
            if(!node->v[prefix[i]-'a'])
            return false;
            node=node->v[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */