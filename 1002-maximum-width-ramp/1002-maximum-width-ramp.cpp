class Solution {
public:
    int maxWidthRamp(vector<int>&arr) {
        int n=arr.size();
        vector<pair<int,int>>temp;

        for(int i=0;i<n;i++){
            temp.push_back({arr[i],i});
        }
        sort(temp.begin(),temp.end());

        int minidx=temp[0].second;
        int result=0;
        int len=0;

        for(int i=1;i<n;i++){
            if(temp[i].second>=minidx){
               len=temp[i].second-minidx;
               result=max(len,result);
            }
            else{
                minidx=temp[i].second;
            }
        } 
        return result;
    }
};