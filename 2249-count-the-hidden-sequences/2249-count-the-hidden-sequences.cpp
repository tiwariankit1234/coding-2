#define ll long long
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll maxsum=INT_MIN,minsum=INT_MAX,sum=0,n=differences.size();
        for(int i=0;i<n;i++){
            sum+=differences[i];
            maxsum=max(maxsum,sum);
            minsum=min(sum,minsum);
        }
        int count=0;
        for(int i=lower;i<=upper;i++){
            if(i+maxsum<=upper and i+minsum>=lower)
            count++;
        }
        return count;
    }
};