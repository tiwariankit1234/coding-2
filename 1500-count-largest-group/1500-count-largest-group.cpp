class Solution {
public:
int f(int n){
    int count=0;
    while(n>0){
        count+=n%10;
        n/=10;
    }
    return count;
}
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int maxfrequency = 1,count=0;
        for (int i = 1; i <= n; i++) {
            int x = f(i);
            mp[x]++;
            if (mp[x] > maxfrequency) {
                maxfrequency = mp[x];
                count=1;
            } else if (mp[x] == maxfrequency) {
               count++;
            }
        }
        return count;
    }
};