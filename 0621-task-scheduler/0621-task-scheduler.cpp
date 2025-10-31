class Solution {
public:
    int leastInterval(vector<char>& arr, int n) {
        unordered_map<char,int> mp;
        for (auto it : arr)
            mp[it]++;

        priority_queue<int> pq;
        for (auto it : mp)
            pq.push(it.second);

        int count = 0;

        while (!pq.empty()) {
            vector<int> temp;

            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                   
                        temp.push_back(freq);
                }
            }

            for (int i = 0; i < ((int)temp.size()); i++) {
                  if(temp[i]>0)
                pq.push(temp[i]);
            }

            if (pq.empty())
                count += temp.size();
            else
                count += n + 1;
        }

        return count;
    }
};
