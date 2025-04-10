#define ll long long
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {

        int n = bound;
        int i = 0, j = 0;
        int limitx = 0, limity = 0, preval = -1;
        for (int i = 0; i <= n; i++) {
            int k = pow(x, i);
            if (k > bound)
                break;
            if (k != preval)
                limitx++;
            else
                break;
            preval = pow(x, i);
        }
        preval = -1;
        for (int i = 0; i <= n; i++) {
            int k = pow(y, i);
              if (k > bound)
                break;
            if (k != preval)
                limity++;
            else
                break;
            preval = pow(y, i);
        }

        set<ll> s;
        vector<int> ans;
        for (int i = 0; i <= limitx; i++) {
            int num = pow(x, i);
            if (num > bound)
                break;
            for (int j = 0; j <= limity; j++) {

                ll newnum = num + pow(y, j);

                if (newnum <= bound)
                    s.insert(newnum);
            }
        }
        for (auto it : s) {
            ans.push_back(it);
        }
        return ans;
    }
};