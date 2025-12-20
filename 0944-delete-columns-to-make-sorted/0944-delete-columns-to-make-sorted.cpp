class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int i=0,j=0,count=0;
         int m=strs[0].size();
         while(j<m){
            int i=1;
            bool flag=false;
            while(i<n){

              if(strs[i][j]<strs[i-1][j]){
                flag=true;
                break;
            }
            i++;
            }
             if(!flag)count++;
             j++;
         }
         return m-count;
    }
};