#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    int minSwaps(std::string s) {
        std::stack<char> stk;
        int swap = 0;

        for (char ch : s) {
            if (ch == '[') {
                stk.push(ch);
            } else {
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                } else {
                    // No match -> swap -> thus push '[' (after swapped)
                    stk.push('[');
                    swap++;
                }
            }
        }

        return swap;
    }
};
