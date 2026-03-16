class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>count1(8*10000+2,0),count2(8*10000+2,0);
        for(int i=0;i<n;i++){
            count1[nums1[i]]++;
            count2[nums2[i]]++;
        }
        vector<int>extraswaps;
        int swaps=0;
        for(int i=0;i<count1.size();i++){
            if((count1[i]+count2[i])%2==1)return -1;
            int sum=(count1[i]+count2[i])/2;
            int diff1=count1[i]-sum;
            if(diff1>0)swaps+=diff1;
            int diff2=count2[i]-sum;
            if(diff2>0)swaps+=diff2;
        //   if(i==10 ||i==20){
        //     cout<<count1[i]<<" "<<count2[i]<<endl;
        //   }
           
        }
        // for(auto it:extraswaps)cout<<it<<" ";
        // cout<<endl;
        // sort(extraswaps.begin(),extraswaps.end());
        // int i=0,j=extraswaps.size()-1;
        // int cost=0;
        // while(i<j){
        //     cost+=extraswaps[i];
        //     extraswaps[j]=extraswaps[j]-extraswaps[i];
        //     i++;
        //     if(extraswaps[j]==0)
        //     j--;
        // }
        

        
        
        return swaps/2;
    }
};