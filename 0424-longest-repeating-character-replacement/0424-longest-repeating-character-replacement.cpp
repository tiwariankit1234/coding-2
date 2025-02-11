class Solution {
public:
// int f(string &s,int l,int r){
//    int hash[26]={0};
//     int mx=1;
//     for(int i=l;i<=r;i++){
//        hash[s[i]-'A']++;
//         mx=max(mx,hash[s[i]-'A']);
//     }
//     return mx;
// }
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0,maxfrequency=0,len=INT_MIN;
          int hash[26]={0};
        while(r<n){
              hash[s[r]-'A']++;
            maxfrequency=max(maxfrequency,hash[s[r]-'A']);
            // cout<<maxfrequency<<" ";
            while(((r-l+1)-maxfrequency)>k){
                hash[s[l]-'A']--;
                l++;
                maxfrequency=0;
                   
   
    for(int i=0;i<26;i++){
       
        maxfrequency=max(maxfrequency,hash[i]);
    }
   
            }
            // cout<<l<<" "<<r<<endl;
            len=max(len,(r-l+1));
            r++;
        }
        
        return len;
    }
};