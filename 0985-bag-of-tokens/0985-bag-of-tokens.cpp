class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        map<int, int> mp;
        for (auto it : tokens)  // Store token frequencies
            mp[it]++;

        int score = 0, maxScore = 0;

        while (!mp.empty() && (power >= mp.begin()->first || (score > 0 && mp.size() > 0))) {
            if (power >= mp.begin()->first) {
                // Play face-up: Gain score
                power -= mp.begin()->first;
                score++;
                maxScore = max(maxScore, score);
                mp[mp.begin()->first]--;

                if (mp[mp.begin()->first] == 0)
                    mp.erase(mp.begin());
            } 
            else if (score > 0) {
                // Play face-down: Gain power
                auto last = prev(mp.end());  // Get largest token
                power += last->first;
                score--;
                mp[last->first]--;

                if (mp[last->first] == 0)
                    mp.erase(last);
            }
        }
        return maxScore;
    }
};
