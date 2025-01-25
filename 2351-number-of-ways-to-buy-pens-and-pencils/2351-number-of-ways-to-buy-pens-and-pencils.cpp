#define ll long long 
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        ll count=0;
        count+=total/cost2+1;
        // cout<<count<<endl;
        while(total>0){
           total-=cost1;
           if(total==0)
           count+=1;
           else if(total>0){
            count+=total/cost2+1;
           }
        }

        return count;
    }
};