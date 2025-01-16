class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int k=nums2.size();

         int ans2=0;
            for(int i=0;i<k;i++){
                ans2^=nums2[i];
            }

            int ans1=0;
            for(int i=0;i<n;i++){
                ans1^=nums1[i];
            }

        if(!(n%2) and !(k%2))
        return 0;
        else if(n%2 and !(k%2)){
           
            return ans2;
        }
    
        else if((n%2)and (k%2)){
            return ans1^ans2;
        }
        else if(!(n%2) and k%2){
            return ans1;
        }
        return 0;
    }
};