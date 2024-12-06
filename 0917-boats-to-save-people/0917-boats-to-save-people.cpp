class Solution {
public:
    int numRescueBoats(vector<int>& pep, int limit) {
        int n=pep.size();
        int i=0,j=n-1,count=0;

         sort(pep.begin(),pep.end());

         while(i<=j){
            if(pep[j]==limit){
                count++;
                j--;
            }
            else{
                int sum=pep[i]+pep[j];
                if(sum==limit){
                    i++;
                    j--;
                    count++;
                }
                else if(sum>limit){
                    j--;
                    count++;
                }

                else if(sum<limit){
                    i++;
                    j--;
                    count++;
                }    
            }
         }
         return count;
    }
};