class Solution {
public:
    string answerString(string word, int k) {
        int n=word.size();
        if(k==1)return word;
       char lexc=word[0];
       int index=0;
       for(int i=1;i<n;i++){
         if(word[i]>lexc){
            lexc=word[i];
            index=i;
         } 
       }
 int length=n-(k-1);
 string ans="";
 for(int j=index;j<n;j++){
    ans=max(ans,word.substr(j,length));
 }
       return ans;
    //   cout<<index<<endl;
      
      
      
    }
};