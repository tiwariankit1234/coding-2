class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        
        // Count frequency of each character
        for (char c : s) {
            mp[c]++;
        }

        // Max heap based on character frequency
        priority_queue<pair<int, char>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        // Check if the most frequent character exceeds the limit
        if (pq.top().first > (n + 1) / 2) return "";

        string t = "";
        while (pq.size() > 1) {
            // Extract the two most frequent characters
            auto [freq1, char1] = pq.top();
            pq.pop();
            auto [freq2, char2] = pq.top();
            pq.pop();

            // Append to result
            t += char1;
            t += char2;

            // Decrease frequency and push back if still available
            if (--freq1 > 0) pq.push({freq1, char1});
            if (--freq2 > 0) pq.push({freq2, char2});
        }

        // If one character remains, append it
        if (!pq.empty()) {
            t += pq.top().second;
        }

        return t;
    }
};
