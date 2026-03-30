class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        unordered_map<char,int>st1,st2,st3,st4;
        for(int i=0;i<n1;i++){
            if(i%2==1){
                st1[s1[i]]++;
            }
            else{
                st2[s1[i]]++;
            }
        }
        for(int i=0;i<n2;i++){
             if(i%2==1){
                st3[s2[i]]++;
            }
            else{
                st4[s2[i]]++;
            }
        }
        if(st1==st3 and st2==st4)return true;
        return false;
    }
};