class Solution {
public:

void prev(vector<int>& arr,int n,vector<int>&prevsmaller){
     stack<int>st;
     st.push(0);
    prevsmaller[0]=-1;     

    for(int i=1;i<n;i++){
        while(!st.empty() and arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.size()==0)prevsmaller[i]=-1;
        else{
            prevsmaller[i]=st.top();
        }
        st.push(i);
    }
      for(auto it:prevsmaller)
        cout<<it<<" ";

       cout<<endl;
}

void next(vector<int>& arr,int n,vector<int>&nextsmaller){
    stack<int>st;
    st.push(n-1);
    nextsmaller[n-1]=n;

    for(int i=n-2;i>=0;i--){
        while(!st.empty() and arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.size()==0)nextsmaller[i]=n;
        else{
            nextsmaller[i]=st.top();
        }
        st.push(i);
    }
    //  cout<<"5"<<endl;
    for(auto it:nextsmaller)
        cout<<it<<" ";

       cout<<endl;
}

 
    int largestRectangleArea(vector<int>& heights) {
         int n=heights.size();
       
         vector<int>prevsmaller(n);
         prev(heights,n,prevsmaller);
        
         vector<int>nextsmaller(n);
         next(heights,n,nextsmaller);
          
           int maxarea=INT_MIN;
         for(int i=0;i<n;i++){
            int currentheight=heights[i];
            int width=nextsmaller[i]-prevsmaller[i]-1;
            int side=min(currentheight,width);
            maxarea=max(maxarea,side*side);
         }
         return maxarea;
    }




    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>>newmatrix(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    newmatrix[i][j]=matrix[i][j]-'0';
                }
                else if(matrix[i][j]=='1'){
                    newmatrix[i][j]+=newmatrix[i-1][j]+1;
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }

        // for(auto it:newmatrix){
        //     for(auto t:it){
        //         cout<<t<<" ";
        //     }
        //     cout<<endl;
        // }
     int maxarea=0;
        for(auto it:newmatrix){
       maxarea=max(maxarea,largestRectangleArea(it));
        }
        return maxarea;
    }




    int maximalSquare(vector<vector<char>>& matrix) {
        return maximalRectangle(matrix);
    }
};