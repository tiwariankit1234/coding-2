class Solution {
public:
    int minLength(string s) {
        while (true) {
            int n = s.size();
            bool found = false;  // To check if we found and erased any "AB" or "CD"
            
            for (int j = 0; j < n - 1; ++j) {
                if ((s[j] == 'A' && s[j + 1] == 'B') || (s[j] == 'C' && s[j + 1] == 'D')) {
                    s.erase(j, 2);  // Erase the pair of characters
                    found = true;
                    break;  // Break the loop and restart to handle the updated string
                }
            }
            
            // If no "AB" or "CD" was found, exit the loop
            if (!found) break;
        }
        
        return s.size();  // Return the final size of the string
    }
};
