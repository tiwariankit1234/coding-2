constexpr int ITEMS = 1001;
constexpr int BUDGET = 1501;
constexpr int FLAG = 2;

class Solution {
public:

    int f(int i, bool flag, int budget,
          vector<pair<int,int>>& temp,
          int (&dp)[ITEMS][BUDGET][FLAG]) {

        if (i == temp.size()) return 0;

        if (dp[i][budget][flag] != -1)
            return dp[i][budget][flag];

        int count = 0;

        if (!flag && budget >= temp[i].second) {
            count = max(count,
                        1 + temp[i].first +
                        f(i, true, budget - temp[i].second,
                          temp, dp));
        }
        else if (flag && budget >= temp[i].second) {
            count = max(count,
                        1 + f(i, true,
                              budget - temp[i].second,
                              temp, dp));
        }

        count = max(count,
                    f(i + 1, false, budget,
                      temp, dp));

        return dp[i][budget][flag] = count;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        vector<pair<int,int>> temp;

        static int dp[ITEMS][BUDGET][FLAG];
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < items.size(); i++) {
            int factor = items[i][0];
            int price  = items[i][1];

            int cnt = 0;

            for (int j = 0; j < items.size(); j++) {
                if (i != j && items[j][0] % factor == 0)
                    cnt++;
            }

            temp.push_back({cnt, price});
        }

        return f(0, false, budget, temp, dp);
    }
};