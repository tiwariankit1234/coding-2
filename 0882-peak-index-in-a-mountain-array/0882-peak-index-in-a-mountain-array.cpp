class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
         int n=arr.size();
         int l=0,h=n-1;
         while(l<=h){
            int mid=(l+h)/2;
            int leftmid=(mid>0)?arr[mid-1]:INT_MIN;
             int rightmid=(mid<n-1)?arr[mid+1]:INT_MIN;
             if(arr[mid]>leftmid and arr[mid]>rightmid)return mid;
                
         if(arr[mid]>=leftmid){   // increasing part
           
           l=mid+1 ;
        }
        else {    // decreasing part
          h=mid-1;
        }
       
    }
    return 0;
    }
    
};