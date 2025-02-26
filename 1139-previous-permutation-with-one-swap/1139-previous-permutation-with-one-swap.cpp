class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size();
       
      
        int index1=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                index1=i;
                break;
            } 
        }
        // cout<<index1<<endl;
        if(index1==-1)return arr;
        int firstelement=arr[index1];
        for(int i=n-1;i>index1;i--){
            int index=i;
            if(arr[i]<firstelement){
                if(i>0){
                    while(arr[index]==arr[index-1]){
                        cout<<index<<endl;
                        index--;
                    }
                    swap(arr[index1],arr[index]);
                    break;
                }
                   
            }
        }

        return arr;
    }
};