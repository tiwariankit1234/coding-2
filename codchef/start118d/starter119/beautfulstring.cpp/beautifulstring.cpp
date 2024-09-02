#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        string str;
        cin >> str;

        int maxCount = 1;
        
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (str[i] == str[i - 1]) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 1;
            }
        }

        cout << maxCount << " ";

        while (q--) {
            char ch;
            cin >> ch;
            str += ch;

            if (ch == str[n-1]) {
               count++;
               maxCount=max(count,maxCount);
            }
            else 
            count=1;

            cout << maxCount << " ";
            n++;
        }

    }
        cout << endl;

    return 0;
}
