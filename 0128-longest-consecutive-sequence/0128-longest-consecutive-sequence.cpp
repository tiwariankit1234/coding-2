class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // set creation 
        // then see x-1 not present 
        // store in some vector 
        // calculate size 
        // calculate maxsize
        int n=nums.size();
        

        unordered_set<int>s(nums.begin(),nums.end());
        if(s.size()==0)return 0;
        if(s.size()==1)return 1;
        vector<int>selectednumber;
        for(int i:s){
            if(!(s.contains(i-1))){
                selectednumber.push_back(i);
            }
        }
        // see for each number is present in s
               int maxcount=1;
        for(auto i:selectednumber){
            int num=i;
            int count=1;
            while((s.contains(num+1))){
                count++;
                maxcount=max(count,maxcount);
                num=num+1;
            }
        }
       return maxcount;

    }
};