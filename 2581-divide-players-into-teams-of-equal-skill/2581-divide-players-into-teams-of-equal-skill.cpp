class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int totalskill=0;
        // to store the total skill
        for(auto i:skill)
        totalskill+=i;


        cout<<totalskill<<endl;

        if((totalskill%(n/2))!=0)return -1;

       

         long long targetskill=totalskill/(n/2);
        int requiredskill=0;

        unordered_map<int,int>mp;
        for(auto i:skill)
         mp[i]++;

         long long totalchemistry=0;

         for(int i=0;i<n;i++){
            int givenskill=skill[i];
            requiredskill=targetskill-givenskill;
           if(mp.find(requiredskill)==mp.end()||mp[requiredskill]!=mp[givenskill]){
           
            
            return -1;

           }
        //    else{
        //     mp[givenskill]--;
        //     mp[requiredskill]--;
        //     if(mp[givenskill]==0)mp.erase(givenskill);
        //     if(mp[requiredskill]==0)mp.erase(requiredskill);
        //     totalchemistry+=givenskill*requiredskill;
        //    }
          totalchemistry+=givenskill*requiredskill;
         }
         return totalchemistry/2;
    }
};