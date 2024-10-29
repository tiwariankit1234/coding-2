// Monotonic stack is a very handy technique when you want to find index of previous lesser(or greater) and next lesser(or greater) element in linear time. Once you understand the usage of monotonic stack, then you'll be able to derive the solution easily in interviews. But yeah you've to see it before unless you are master of combining data-structures on the fly.


// I was able to solve this one in about 20 mins without seeing it before. This was my intuition to realise to use a stack:

// At first I looked at the problem and I was guessing there will be some o(n) or o(nlogn) solution. This makes me think that the answer can be computed during iteration, like best=max(best, current) ect.

// Then notice, for a given height, if you only know heights you have seen so far, you are only concerned with heights earlier and less than or equal than the current height. This means there is an ascending staircase pattern. Then you have to figure out how to maintain an ascending staircase. At this point it's easy to see a stack, you pop off everything at the top of the staircase and then you add new stuff on top.





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
     cout<<"5"<<endl;
    for(auto it:nextsmaller)
       cout<<it<<" ";

       cout<<endl;
}

 
    int largestRectangleArea(vector<int>& heights) {
         int n=heights.size();
         if(n==1)return heights[0];
         vector<int>prevsmaller(n);
         prev(heights,n,prevsmaller);
        
         vector<int>nextsmaller(n);
         next(heights,n,nextsmaller);
          
           int maxarea=0;
         for(int i=0;i<n;i++){
            int currentheight=heights[i];
            int width=nextsmaller[i]-prevsmaller[i]-1;
            int area=currentheight*width;
            maxarea=max(maxarea,area);
         }
         return maxarea;
    }
};