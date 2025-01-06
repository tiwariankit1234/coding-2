class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.size();
    vector<int> changes(n+1, 0);
    
    // Step 1: Apply the shifts to the 'changes' array
    for (auto it : shifts) {
        int first = it[0];
        int second = it[1];
        int dir = it[2];
        
        if (dir == 1) {
            changes[first] += 1;  // Forward shift from 'first'
            if (second + 1 < n) changes[second + 1] -= 1;  // Stop effect after 'second'
        } else {
            changes[first] -= 1;  // Backward shift from 'first'
            if (second + 1 < n) changes[second + 1] += 1;  // Stop effect after 'second'
        }
    }

    // Step 2: Apply prefix sum to accumulate all shifts
    for (int i = 1; i < n; i++) {
        changes[i] += changes[i - 1];
    }

    // Step 3: Create the result string with the applied shifts
    string newstring;
    for (int i = 0; i < n; i++) {
        // Calculate the new character after the shift
        char newChar = (char)((s[i] - 'a' + changes[i]%26 + 26) % 26 + 'a');
        newstring.push_back(newChar);
    }

    return newstring;
}

};