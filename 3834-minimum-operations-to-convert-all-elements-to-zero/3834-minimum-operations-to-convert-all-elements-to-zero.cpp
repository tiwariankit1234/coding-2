class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                    unordered_set<int> s;
                while (st.size() > 0) {
                    s.insert(st.top());
                    st.pop();
                }
                count += s.size();
                s.clear();
            }

            else if (st.size() > 0 and nums[i] < st.top()) {
                unordered_set<int>s;
                while (st.size() > 0 and nums[i] < st.top()) {
                    
                    s.insert(st.top());
                    st.pop();
                    
                }
                count+=s.size();
                st.push(nums[i]);
               
            } else if (st.size() > 0 and nums[i] == st.top()) {
                continue;
            } else {
                st.push(nums[i]);
            }
        }

           unordered_set<int>s;
        while (st.size() > 0) {
            s.insert(st.top());
            st.pop();
        }
        count += s.size();
        return count;
    }
};