class Solution {
public:
#define ll long long

    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       ll score=0;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});

           
            
        }
        
        
        unordered_map<int,int>mp;
        while(pq.size()>0){
            auto p=pq.top();
            pq.pop();
            
            int num=p.first;
            int index=p.second;

            // cout<<num<<" "<<index<<endl;
            if(mp.find(index)!=mp.end()){
                continue;
            }
            else{
                // cout<<num<<endl;
                score+=num;
                mp[index]++;
                mp[index-1]++;
                mp[index+1]++;
            }
        }
        return score;
    }
};