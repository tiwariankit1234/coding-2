class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
         unordered_set<int>s(arr.begin(),arr.end());
         int maxlen=0;
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i],b=arr[j];
                int c=a+b;
                int len=2;
                while(s.find(c)!=s.end()){
                    len++;
                    a=b;
                    b=c;
                    maxlen=max(len,maxlen);
                    c=a+b;
                }
            }
         }
         return maxlen;
    }
};