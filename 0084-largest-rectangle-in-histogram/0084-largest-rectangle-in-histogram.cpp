class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(-1);
        int n=height.size();
        // this problem should be solved using stack .
        /* whenever you see a monotonic increase in the input which      
		would yield  the answer closest to 
		required you gotta understand that you should
		use  a stack datastructure to  calculate the answer*/
        // so let's begin by creating a stack and ans that we return 
       
        //just to make our code understand better i'm adding 0 at the end of
        //heights
    
        /* how do you add the elements to the stack ? mmmmmm? okay 
		let us think 
        way ,lets add all the ascending order elements to the stack so that 
		it
        looks like climbing steps .coz in that way we can have atleast the 
		min
        size step * number of elements in the stack .if we encounter any 
		bar with         lesser height than the top element of the stack ,we 
		will compute the 
        existing stack element area and pop the top element just to check 
		if the 
        current top < bar height ,if it is so ..add it to the stack ..i think it        
		will be more clearer if you go through the code*/
         //very important note .. we are adding indices ..not the values
            stack<int>st;
            st.push(0);
            int area=INT_MIN,base=0;
            for(int i=1;i<n;i++){
                while(!st.empty() and height[st.top()]>height[i]){
                    int high=height[st.top()];
                    st.pop();
                    if(st.empty()) base=-1;
                    else
                    base=st.top();
                  
                    area=max(area,high*(i-base-1));
                    // cout<<i<<" "<<" "<<height[i]<<" "<<high<<" "<<base<<endl;
                }
                st.push(i);
            }
            return area;

                //here we are checking if stack is empty or if we encounter 
				
                // number that doesn't satisfy our stack filling property
                

                //this is to check if stack is empty, if so we will just take the                 //index
    
                // this is just to take the max area covered so far
            
            //we push into the stack as long as it satsifies our stack condition
        
    
        // i know it's not a very clever explanation ..but i tried to explain 
        //whatever i can ...HAPPY CODING!!
    }
};