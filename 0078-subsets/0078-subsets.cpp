class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       // first calculate total subsets
       // iterate over each number and see if its bit 1 insert in list 
       int n=nums.size();
       int totalsubsets=1<<n;
       
           vector<vector<int>>ans;
       for(int i=0;i<totalsubsets;i++){
        // checkeach bit
           int k=i;
           
           int count=0;
           vector<int>temp;
           while(k!=0){
             if(k%2==1){
                temp.push_back(nums[count]);
            }
            k=k>>1;
            cout<<"count"<<count<<endl;
            count++;

           }
           ans.push_back(temp);
        }
           
       
       return ans;
    }
};