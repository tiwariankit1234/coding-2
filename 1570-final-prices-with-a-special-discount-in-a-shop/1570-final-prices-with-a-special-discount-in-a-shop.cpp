class Solution {
public:


vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result vector with -1
    stack<int> st; // Stack to keep track of elements
     result[n-1]=arr[n-1];
     st.push(arr[n-1]);
    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; --i) {

        while(!st.empty() and arr[i]<st.top()){
            st.pop();
        }
        if(!st.empty()){
            result[i]=st.top();
        }
        else{
            result[i]=-1;
        }
        st.push(arr[i]);

    }

    return result;
}



    vector<int> finalPrices(vector<int>& prices) {
        vector<int>nextvector= nextSmallerElement(prices);

        for(auto it:nextvector)
        cout<<it<<" ";

        cout<<endl;
        for(int i=0;i<prices.size();i++){
            if(i!=(prices.size()-1) and nextvector[i]!=-1)
            prices[i]=prices[i]-nextvector[i];
        }
        
        return prices;
    }
};