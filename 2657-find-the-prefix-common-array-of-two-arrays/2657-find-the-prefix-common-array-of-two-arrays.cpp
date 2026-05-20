class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& arr1, vector<int>&arr2) {
        int n=arr1.size();
        unordered_set<int>s1,s2;
        vector<int>ans;
        int count=0;
        for(int i=0;i<n;i++){
            if(s2.find(arr1[i])!=s2.end()){
                count++;
            }
            s1.insert(arr1[i]);
            if(s1.find(arr2[i])!=s1.end()){
                count++;
            }
            s2.insert(arr2[i]);
            ans.push_back(count);
        }
        return ans;
    }
};