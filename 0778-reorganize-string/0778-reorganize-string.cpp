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
        while (!pq.empty()) {
            // Extract the most frequent character
            auto [freq1, char1] = pq.top();
            pq.pop();
            t += char1;

            // Extract the second most frequent character if available
            if (!pq.empty()) {
                auto [freq2, char2] = pq.top();
                pq.pop();
                t += char2;

                // Push the second character back if it still has occurrences left
                if (--freq2 > 0) pq.push({freq2, char2});
            }

            // Push the first character back if it still has occurrences left
            if (--freq1 > 0) pq.push({freq1, char1});
        }

        return t;
    }
};
