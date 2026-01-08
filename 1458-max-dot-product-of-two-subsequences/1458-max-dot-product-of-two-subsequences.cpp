class Solution {
public:
int dp[502][502];
int f(int i,int j,vector<int>& nums1,vector<int>& nums2){
    int n1=nums1.size(),n2=nums2.size();
    if(i==n1 and j==n2)return -1e8;
     if(i==0 and j==n2)return -1e8;
    if(j==0 and i==n1)return -1e8;
    if(j==n2)return -1e8;
    if(i==n1)return -1e8;
    if(dp[i][j]!=-1e8)return dp[i][j];
    int ans=-1e8;
    int take1=-1e8;
    take1=f(i+1,j+1,nums1,nums2)+nums1[i]*nums2[j];
    take1=max(take1,nums1[i]*nums2[j]);
    int notake1=-1e8;
    notake1=f(i,j+1,nums1,nums2);
    int notake2=-1e8;
    notake2=f(i+1,j,nums1,nums2);
    return dp[i][j]=max({take1,notake1,notake2});

}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<502;i++){
            for(int j=0;j<502;j++){
                dp[i][j]=-1e8;
            }
        }
       
        int x=f(0,0,nums1,nums2);
        int max1=*max_element(nums1.begin(),nums1.end());
        int max2=*max_element(nums2.begin(),nums2.end());
        int min1=*min_element(nums1.begin(),nums1.end());
        int min2=*min_element(nums2.begin(),nums2.end());
        if(x==0){
            // if(max1<0 and max){

            // }
            for(int i=0;i<nums1.size();i++){
                if(nums1[i]==0){
                    return 0;
                }
            }
            for(int i=0;i<nums2.size();i++){
                if(nums2[i]==0)return 0;
            }
            return max((max1*min2),(min1*max2));

        }
         return x;
        
    }
};