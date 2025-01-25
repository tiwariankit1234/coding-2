class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
      
        vector<pair<int,int>>diff;
        for(int i=0;i<n;i++){
            diff.push_back({reward1[i]-reward2[i],i});
        }
       sort(diff.rbegin(),diff.rend());
       int j=0;
       int sum=0;
       while(k>0 ){
        sum+=reward1[diff[j].second];
        k--;
        j++;
       }
       while(j<n){
        sum+=reward2[diff[j].second];
        j++;
       }
       return sum;
    }
};