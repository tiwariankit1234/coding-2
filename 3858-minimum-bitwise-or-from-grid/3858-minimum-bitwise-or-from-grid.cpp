class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        
        int ans = (1 << 17) - 1;   // allow all bits initially
        
        for(int bit = 16; bit >= 0; bit--){
            
            int candidate = ans ^ (1 << bit);   // try removing this bit
            
            bool possible = true;
            
            for(auto &row : grid){
                bool ok = false;
                
                for(int x : row){
                    if((x | candidate) == candidate){
                        ok = true;
                        break;
                    }
                }
                
                if(!ok){
                    possible = false;
                    break;
                }
            }
            
            if(possible){
                ans = candidate;
            }
        }
        
        return ans;
    }
};
