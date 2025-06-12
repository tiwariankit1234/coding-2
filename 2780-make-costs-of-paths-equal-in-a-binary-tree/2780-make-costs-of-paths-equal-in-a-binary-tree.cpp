class Solution {
public:
    
   int f(int idx,vector<int>& cost, int& temp) {
        int n = cost.size();
        if (idx >=n) {

            return 0;
        }
      
       int left=f(2 * idx,cost, temp);
        int right=f(2*idx+1,cost,temp);
       
         if (2 * idx < n and (2 * idx + 1) < n) {
            int newsum = abs(left-right);
            temp += newsum;
        }
        return cost[idx]+max(left,right);
    }

    int minIncrements(int n, vector<int>& cost) {
        int temp = 0;
       
        cost.insert(cost.begin(), 0);
        f(1,cost, temp);
         
        return temp;
    }
};