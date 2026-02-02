class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        cout<<s[i]<<" "<<s[j]<<endl;
        while (i < j) {
            while (j>=0 and !(s[j] >= 'a' and s[j] <= 'z')) {
                j--;
            }
            while (i<n and !(s[i] >= 'a' and s[i] <= 'z') and i<n) {
                i++;
            }
            if(i>=0 and j<n and i<j )
            swap(s[i], s[j]);
            // cout<<i<<" "<<j<<endl;
            i++;
            j--;
        }
        cout<<i<<" "<<j<<endl;
        i = 0, j = n - 1;

        while (i < j) {
            while (j>=0 and !ispunct(s[j])) {
                j--;
            }
            while (i<n and !ispunct(s[i]) ) {
                i++;
            }
            cout<<i<<" "<<j<<endl;
            if(i>=0 and j<n and i<j and i<n and j>=0)
            swap(s[i], s[j]);

            i++;
            j--;
        }
        return s;
    }
};