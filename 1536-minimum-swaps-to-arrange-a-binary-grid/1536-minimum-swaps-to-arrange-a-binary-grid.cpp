class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid.size();
         vector<int>required,temp;
         for(int i=0;i<m;i++){
            required.push_back(n-1-i);
         }
         for(int i=0;i<m;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
              if(grid[i][j]==1)break;
              count++;
            }
            temp.push_back(count);
         }
         int swaps=0;
         for(int i=0;i<n;i++){
            bool flag=false;
            if(temp[i]<required[i]){
                int index=-1;
                for(int j=i+1;j<(n);j++){
                    if(temp[j]>=required[i]){
                        index=j;
                        break;
                    }
                }
                     if(index!=-1){
                    while(index>i){
                        swap(temp[index],temp[index-1]);
                        swaps++;
                        index--;
                    }

                }
                
            }
         }
         for(int i=0;i<n;i++){
            if(temp[i]<required[i])return -1;
         }

         return swaps;
    }
};