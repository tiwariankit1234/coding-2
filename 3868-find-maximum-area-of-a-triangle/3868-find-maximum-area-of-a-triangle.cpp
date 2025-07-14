#define ll long long

class Solution {
public:
    long long maxArea(vector<vector<int>>& co) {
        vector<vector<ll>> coords;
        for (auto it : co) {
            coords.push_back({it[0], it[1]});
        }
        ll n = coords.size();
        vector<vector<ll>> xby = coords;
        sort(xby.begin(), xby.end());
        vector<vector<ll>> yby = coords;
        sort(yby.begin(), yby.end(),
             [](vector<ll>& a, vector<ll>& b) { if(a[1]==b[1]){
                return a[0]<b[0];
             }
             return a[1]<b[1]; });

        ll area = INT_MIN;
        for(auto it:yby){
            for(auto k:it){
                cout<<k<<" ";
            }
            cout<<endl;
        }

        ll i = 0, j = 1, count = 0;
        while (j < n) {
            if (xby[j][0] == xby[i][0]) {
                count += (xby[j][1] - xby[j - 1][1]);
                j++;
                if (j == n) {
                    ll height = max(abs(xby[n - 1][0] - xby[i][0]),
                                    abs(xby[0][0] - xby[i][0]));
                    // cout<<count<<" "<<height<<endl;
                    if (height > 0)
                        area = max(area, (ll)count * (ll)height);
                }

            } else {

                ll height = max(abs(xby[n - 1][0] - xby[i][0]),
                                abs(xby[0][0] - xby[i][0]));
                // cout<<count<<" "<<height<<endl;
                if (height > 0)
                    area = max(area, (ll)count * (ll)height);
                i = j;
                j++;
                count = 0;
            }
        }
        cout << area << endl;
        i = 0, j = 1, count = 0;

        while (j < n) {
            if (yby[j][1] == yby[i][1]) {
                count += (yby[j][0] - yby[j - 1][0]);
                j++;
                if (j == n) {
                    ll height = max(abs(yby[n - 1][1] - yby[i][1]),
                                    abs(yby[0][1] - yby[i][1]));
                    if (height > 0)
                        area = max(area, (ll)count * (ll)height);
                }

            } else {
                ll height = max(abs(yby[n - 1][1] - yby[i][1]),
                                abs(yby[0][1] - yby[i][1]));
                if (height > 0)
                    area = max(area, (ll)count * (ll)height);
                i = j;
                j++;
                count = 0;
            }
        }
        if (area == 0)
            return -1;
        return area;
    }
};