class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // ek window ka nikal lunga
       vector<int>ans;
       int n=nums.size();

           deque<int>dq;
        
       for(int i=0;i<k;i++){
         while(!(dq.empty()) and dq.front()<=(i-k)){
            dq.pop_front();
         }
        while(!dq.empty() and nums[i]>=nums[dq.back()]){
            dq.pop_back(); 
        }

 
        dq.push_back(i);
        // cout<<dq.front()<<" "<<endl;
     }
      ans.push_back(nums[dq.front()]);
     
       int j=k;
       while(j<n){

           while(!dq.empty() and dq.front()<=(j-k)){
            dq.pop_front();
         }
               
    
        while(!dq.empty() and nums[j]>=nums[dq.back()]){
            dq.pop_back(); 
        }

        dq.push_back(j);
       
         

      
       
        
          ans.push_back(nums[dq.front()]);

          j++;
       }
       return ans;
    }
};