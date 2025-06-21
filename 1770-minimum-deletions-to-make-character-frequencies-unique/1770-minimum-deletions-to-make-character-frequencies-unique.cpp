class Solution {
public:

    int minDeletions(string st) {
        int n=st.size();
        vector<int>mp(26,0);
        for(auto it:st)
         mp[it-'a']++; 
         vector<int>freq;
         for(auto it:mp){
            if(it!=0)
            freq.push_back(it);
         }
         sort(freq.begin(),freq.end());
         int count=0;
         unordered_set<int>s;
        
         for(int i=0;i<freq.size();i++){
            if(s.find(freq[i])==s.end()){
                s.insert(freq[i]);
            }
            else{
                
                for(int j=freq[i];j>0;j--){
                    if(s.find(j)==s.end()){
                        s.insert(j);
                        break;
                    }
                    else{
                    count++;
                    }
                }
            }
         }
         return count;
    }
};