class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size(),k=s2.size();
        int i=0,j=0,cnt=0;
        vector<int>freq1(26,0),freq2(26,0);
        for(int i=0;i<n;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        if(freq1!=freq2) return false;
      

        while(i<n and j<k){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
                j++;
                cnt++;
                while(i<n and j<n){
                    if(s1[i]==s2[j]){
                        i++;
                        j++;
                    }
                    else{
                         i++;
                         j++;
                         cnt++;
                         while(i<n and j<k){
                            if(s1[i]==s2[j]){
                                i++;
                                j++;
                            
                            }
                            else{
                                return false;
                            }
                         }
                    }
                }
            }
        }
        if(i==n and j==n and (cnt==2)|| (cnt==0))return true;
        else
        return false;
    }
};