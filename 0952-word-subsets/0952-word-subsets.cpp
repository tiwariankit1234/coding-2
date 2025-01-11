class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // first create frequency map for words2
        // create freqeuncey map for words1
        // then iterate in frequency map of words1 if frequency of a
        // word is less than flag=false and break it
        // if flag true then insert it 
        // mistake index ka 
     
         vector<string>ans;
        
              vector<int>maxfrequency(26,0);
         for(auto it:words2){
            string s=it;
            int n=s.size();
             vector<int>freqmap2(26,0);
            for(int i=0;i<n;i++){
                freqmap2[s[i]-'a']++;
                maxfrequency[s[i]-'a']=max(maxfrequency[s[i]-'a'],freqmap2[s[i]-'a']);
            }
         }
        //  for(auto it:freqmap2)
        //  cout<<it<<" ";
        //  cout<<endl;
        int n=words1.size();
           for(int i=0;i<n;i++){
            string s=words1[i];
            // cout<<it<<endl;
            int k=s.size();
            cout<<s<<endl;
            vector<int>freqmap1(26,0);
            for(int i=0;i<k;i++){
                freqmap1[s[i]-'a']++;
            }

        //      for(auto it:freqmap1)
        //       cout<<it<<" ";
        //  cout<<endl;
            // check this string can be inserted in my ans;
            bool flag=true;
            for(int i=0;i<26;i++){
                if((maxfrequency[i])>(freqmap1[i])){
                    flag=false;
                    cout<<i<<endl;
                    break;
                }
            }
            // if(s=="leetcode"){
            // for(auto it:freqmap1){
            //     cout<<it<<" ";
            // }
            // } 
            cout<<endl;
            if(flag)ans.emplace_back(s);
            // for(auto it:ans)
            // cout<<it<<" ";
            // cout<<endl;
         }

      return ans;

    }
};