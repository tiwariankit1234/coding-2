class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int totalapple=accumulate(apple.begin(),apple.end(),0);
        int j=capacity.size()-1;
        while(j>=0){
           totalapple=totalapple-capacity[j];
           if(totalapple<=0){
            return (capacity.size()-j);
           }
           j--;
        }
        return 0;
    }
};