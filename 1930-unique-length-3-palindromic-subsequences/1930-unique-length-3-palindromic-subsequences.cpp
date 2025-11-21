class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        int count=0;
        vector<int>first(26,-1),last(26,-1);
        // store the first and last occurence of each character
        for(int i=0;i<n;i++){
            if(first[s[i]-'a']==(-1)){
                first[s[i]-'a']=i;
            }
            last[s[i]-'a']=i;
        }
     //   for(auto it:first)
//cout<<it<<" ";
      //  cout<<endl;

        //  for(auto it:last)
        // cout<<it<<" ";
        // cout<<endl;

        for(int i=0;i<n;i++){
            if(first[s[i]-'a']!=-1 and last[s[i]-'a']!=-1){  
                int index1=first[s[i]-'a'];
                if(index1<i)continue;
                int index2=last[s[i]-'a'];
                unordered_set<char>st;
                for(int j=(index1+1);j<index2;j++){
                    st.insert(s[j]);
                }
            //    cout<<i<<" "<<st.size()<<endl;
                count+=st.size();
            }
        }
        return count;
    }
};