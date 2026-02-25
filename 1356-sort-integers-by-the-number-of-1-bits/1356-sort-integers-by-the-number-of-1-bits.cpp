class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int x,int y){
            int p=__builtin_popcount(x),q=__builtin_popcount(y);
            if(p==q)return x<y;
            return p<q;
        });
        return arr;
    }
};