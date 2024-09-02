#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> count(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum <= n)
                    count[sum]++;
                else
                    break;
            }
        }

        for (int i = 1; i <= n; i++)
            cout << count[i] << " ";
        
        cout << endl;
    }
}