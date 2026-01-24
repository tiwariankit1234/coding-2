class TrieNode{
public:
TrieNode* links[26];
bool isend;
TrieNode(){
    for(int i=0;i<26;i++){
        links[i]=nullptr;
    }
    isend=false;
}
};

class WordDictionary {
public:
TrieNode* root=new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->links[word[i]-'a']){
                temp->links[word[i]-'a']=new TrieNode();
            }
            temp=temp->links[word[i]-'a'];
        }
        temp->isend=true;
    }
    bool dfs(int index,string& word,TrieNode* temp){
       int n=word.size();
    //    cout<<word[index]<<endl;
       if(index==n){
         return temp->isend;
       }
       if(word[index]=='.'){
         for(auto it:temp->links){
            if(it and dfs(index+1,word,it)){
               return true;
            }
         }
       }
       else if(word[index]!='.'){
        // cout<<word[index]<<endl;
        if(!temp->links[word[index]-'a'])return false;
          return dfs(index+1,word,temp->links[word[index]-'a']);
       }
       return false;
    }
    
    bool search(string word) {
        TrieNode* temp=root;
        return dfs(0,word,temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */