// sabse pehle dekho i previous i-1 se kaise different number ko produce karega
// agar nahi toh break down karo problem ko different set me har subarray ka bitwise or nikalo 
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> s;
        set<int> t;
        for (int i : A) {
            set<int> r;
            r.insert(i);
            
    }
};