class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int>mp;
        int n=hours.size();

     

        for(int i=0;i<n;i++){
        hours[i]=hours[i]%24;
      
        }

        int count=0;

        for(int i=0;i<n;i++){
            int required=(24-hours[i])%24;
           if(mp.find(required)!=mp.end()){
            count+=mp[required];
           }
             mp[hours[i]]++;
        }
        return count;
        


    }
};