class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //pehle ek ans vector initialise karenge
        // then traverse query vector 
        // for(each i we will be storing value in ans vector)
        int n=arr.size();
        int k=queries.size();
        vector<int>ans(k);
        vector<int>prefixxor(n);
       
        prefixxor[0]=arr[0];
        
        for(int i=1;i<n;i++){
            prefixxor[i]=prefixxor[i-1]^arr[i];
        }

      for(int i=0;i<k;i++){
        int left=queries[i][0];
        int right=queries[i][1];
        if((left-1)<0){
            ans[i]=0^prefixxor[right];
        }
        else{
            ans[i]=prefixxor[left-1]^prefixxor[right];
        }
        
        cout<<ans[i]<<" "<<endl;
      }  
          // second approach
          //make prefixxor array and then do xor of left-1 and right










        // for(int i=0;i<k;i++){
        //     int firstindex=queries[i][0];
        //     int secondindex=queries[i][1];
        //     int temp=0;
        //     for(int j=firstindex;j<=secondindex;j++){
        //       temp=temp^arr[j];
        //     }
        //     ans[i]=temp;
        //     // if(firstelement==secondelement){
        //     //     ans[i]=firstelement;
        //     // }
        //     // else{
        //     //  ans[i]=firstelement^secondelement;
        //     // }
        // }
        return ans;
    }
};