class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr(n, 0);
        int j = 0, res = 0, idx = -1,personcount=n;
        while (personcount> 1) {
            int steps = k - 1;
            while (j < n and steps > 0) {
                if (arr[j] == 0) {
                    steps--;
                }
                
                j = (j + 1) % n;
              
            }
              while (arr[j] == 1) {
                j = (j + 1) % n;
            }
            arr[j]=1;
            personcount--;

                while(j<n and arr[j]==1){
                      j=(j+1)%n;
                }
      
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                res=i;
                break;
            }
        }
         return res + 1;
    }
   

};
