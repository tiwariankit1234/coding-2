class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
         vector<int> copy(nums.begin(), nums.end());
        copy.insert(copy.end(), nums.begin(), nums.end());

        //  for(auto it:copy)
        //  cout<<it<<" ";

         cout<<endl;

         
           int n=copy.size(),l=0,r=1,count=0;
        //    cout<<n<<endl;
             while(l<(n/2)){
               
                if(copy[r]==copy[r-1]){
                    l=r;
                }
                
                if((r-l+1)==k){
                    count++;
                    l++;
                }
                r++;
               
                //  cout<<l<<" "<<r<<endl;
             }
           return count;
    }
};