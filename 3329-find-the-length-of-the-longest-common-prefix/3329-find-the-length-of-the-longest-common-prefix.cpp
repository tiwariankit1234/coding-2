class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
         int n1=arr1.size(),n2=arr2.size();
         unordered_set<int>s;

         for(int num:arr1){
            while(num>0){
                s.insert(num);
                num/=10;
            }
         }

           for(auto it:s){
            cout<<it<<" "<<endl;
           }

         int size=0,maxsize=0;
        for(int num:arr2){
             string k=to_string(num);
             int numsize=k.size();
                
                while(num>0){
                    // cout<<num<<endl;
                       if(s.contains(num)){
                        // cout<<num<<endl;
                    maxsize=max(numsize,maxsize);
                    
                       }
                       numsize--;
                    num/=10;
                }
            }

                return maxsize;
        }
};