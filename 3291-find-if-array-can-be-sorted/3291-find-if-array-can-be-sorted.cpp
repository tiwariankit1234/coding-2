class Solution {
public:
bool issorted(vector<int>&arr){
    int n=arr.size();
    int count=0;
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
            count++;
        }
    }
    if(count==(n-1))return true;
    return false;
}
    bool canSortArray(vector<int>& arr) {
        int n=arr.size();
        bool t=issorted(arr);
        if(t==1)return true;
        vector<int>newarray(n);
        for(int i=0;i<n;i++){
            newarray[i]=__builtin_popcount(arr[i]);
        }
         int i=0,j=0;
         while(j<n){
            if(newarray[i]==newarray[j]){
                j++;
            }
            else{
         
                sort(arr.begin()+i,arr.begin()+j);
                i=j;
                j++;
            }
         }
         sort(arr.begin()+i,arr.end());
        return issorted(arr);
    }
};