class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int k=s2.size();

         vector<int>arr1(26);
         vector<int>arr2(26);

         for(int i=0;i<n;i++)
         arr1[s1[i]-'a']++;
             
         int i=0,j=0;
         int count=0;
         while(j<k){
            arr2[s2[j]-'a']++;
            count++;
            if(count>n){
                arr2[s2[i]-'a']--;
                i++;
                count=n;
            }
            if(arr1==arr2)return true;
            j++;

         }
         return false;
    }
};