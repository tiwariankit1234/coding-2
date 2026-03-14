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
        for(int i=0;i<count1.size();i++){
            if((count1[i]+count2[i])%2==1)return -1;
          int diff=abs((count1[i]-count2[i])/2);
        //   if(i==10 ||i==20){
        //     cout<<count1[i]<<" "<<count2[i]<<endl;
        //   }
          
          extraswaps.push_back(diff);
        }
        // for(auto it:extraswaps)cout<<it<<" ";
        // cout<<endl;
        sort(extraswaps.begin(),extraswaps.end());
        int i=0,j=extraswaps.size()-1;
        int cost=0;
        while(i<j){
            cost+=extraswaps[i];
            extraswaps[j]=extraswaps[j]-extraswaps[i];
            i++;
            if(extraswaps[j]==0)
            j--;
        }
        

        
        
        return cost;
    }
};