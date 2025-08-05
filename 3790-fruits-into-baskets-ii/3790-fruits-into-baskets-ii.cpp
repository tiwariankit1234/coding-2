class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fr, vector<int>& bsk) {
        int n=fr.size();
        vector<bool>flag(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            int num=fr[i];
           
            for(int j=0;j<n;j++){
                if(bsk[j]>=num and flag[j]==false){
                    flag[j]=true;
                   
                    break;
                }
            }
        
        }
        for(auto it:flag)
            {
                if(it==false)
                    count++;
            }
        return count;
    }
};