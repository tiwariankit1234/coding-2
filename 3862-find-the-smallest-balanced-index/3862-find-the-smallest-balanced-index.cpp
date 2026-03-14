#define ll long long

class Solution {
public:
    int smallestBalancedIndex(vector<int>& temp) {
        int n = temp.size();

        vector<ll> sum(n);
        sum[0] = temp[0];

        ll maxsum = sum[0];
        for(int i=1;i<n;i++){
            sum[i] = sum[i-1] + temp[i];
            maxsum = max(maxsum, sum[i]);
        }

       long long product = 1;

for(int i=n-1;i>=0;i--){
    long long remainsum = (i>0)?sum[i-1]:0;

    if(product == remainsum)
        return i;

    if(product>=(1e10) and temp[i]>=(1e5))return -1;

    if(product > maxsum)
        return -1;
    product=product*temp[i];


}

        return -1;
    }
};