class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<bool>flag(26,false);
        vector<int>mp(26,0);
        for(char ch:s){
        mp[ch-'a']++;
        
        }
        stack<char>st;
        for(int i=0;i<n;i++){
            // cout<<s[i]<<endl;
            if(flag[s[i]-'a']==false){
                // cout<<s[i]<<endl;
                while(!st.empty() and st.top()>s[i] and mp[st.top()-'a']>=1){
                    flag[st.top()-'a']=false;
                        // cout<<st.top()<<" ";
                    st.pop();
               
                }
                // cout<<endl;
                        
                    st.push(s[i]);
                    flag[s[i]-'a']=true;
                 mp[s[i]-'a']--;
                 
                
            }
            else{
                mp[s[i]-'a']--;
            }
        }

            string t="";
            while(st.size()>0){
                t+=st.top();
                st.pop();
            }
            reverse(t.begin(),t.end());
            return t;
    }
};