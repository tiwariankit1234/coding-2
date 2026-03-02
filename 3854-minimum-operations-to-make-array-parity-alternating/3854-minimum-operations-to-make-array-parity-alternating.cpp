class Solution {
public:
    vector<int> f(vector<int>& nums, int parity) {
        int n = nums.size();
        int maxelement = INT_MIN, minelement =INT_MAX;
        int i = 0, changes = 0;
        vector<int> temp1;
        while (i < (n)) {
            // cout << i << " " << parity << " " << maxelement << " " << minelement
            //      << endl;
            //  if(i+1<n and (nums[i]%2)==parity and (nums[i+1]%2)==(parity^1)){
            //     maxelement=max(maxelement,nums[i]);
            //     maxelement=max(maxelement,nums[i+1]);
            //     minelement=min(minelement,nums[i]);
            //     minelement=min(minelement,nums[i+1]);
            //  }
            if ((abs(nums[i]) % 2) == (parity)) {
                // cout<<nums[i]%2<<" "<<parity<<" "<<"isblock"<<" "<<endl;
                maxelement = max(maxelement, nums[i]);
                minelement = min(minelement, nums[i]);
                if (i + 1 < n) {
                    if ((abs(nums[i + 1]) % 2) == (parity ^ 1)) {
                        maxelement = max(maxelement, nums[i + 1]);
                        minelement = min(minelement, nums[i + 1]);
                    }
                    else if(((abs(nums[i + 1]) % 2)) != (parity ^ 1)) {
                        maxelement = max(maxelement, nums[i + 1] - 1);
                        minelement = min(minelement, nums[i + 1] + 1);
                        changes++;
                    }
                }
                 
                    
                
            }

            //  if(count==2){
            //     i+=2;
            //     continue;
            //  }
            else {
                if (abs(nums[i]) % 2 != parity) {
                    changes++;
                    
                    maxelement = max(maxelement, nums[i] - 1);
                    minelement = min(minelement, nums[i] + 1);
                    
                }
                else{
                    maxelement=max(maxelement,nums[i]);
                    minelement=min(minelement,nums[i]);
                }
                if (i + 1 < n and (abs(nums[i + 1]) % 2) != (parity ^ 1)) {
                    changes++;
                    maxelement = max(maxelement, nums[i + 1] - 1);
                    minelement = min(minelement, nums[i + 1] + 1);
                }
                else{
                    if(i+1<n){
                    maxelement=max(maxelement,nums[i+1]);
                    minelement=min(minelement,nums[i+1]);
                    }
                }
            }
            i += 2;
                // cout << maxelement << " " << minelement <<" "<<parity<<endl;
        }
    
        temp1.push_back(changes);
        temp1.push_back(max((maxelement - minelement),1));
        return temp1;
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return {0,0};
        vector<int> temp1 = f(nums, 0);
        vector<int> temp2 = f(nums, 1);
        // for (auto it : temp1) {
        //     cout << it << " ";
        // }
        // cout << endl;
        // for (auto it : temp2) {
        //     cout << it << " ";
        // // }
        // cout << endl;
        if (temp1[0] < temp2[0]) {
            return temp1;
        } else {
            if (temp1[0] == temp2[0]) {
                if (temp1[1] < temp2[1])
                    return temp1;
            }
            return temp2;
        }
    
    }
};