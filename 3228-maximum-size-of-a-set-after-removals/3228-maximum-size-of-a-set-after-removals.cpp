class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int k = nums1.size();
        map<int, int> mp1, mp2;
        set<int> s;

        for (auto it : nums1)
            mp1[it]++;

        for (auto it : nums2)
            mp2[it]++;

        for (auto it : mp1) {
            if (mp2[it.first] > 0) {
                s.insert(it.first);
            }
        }

        int totalelementremoval = 0;
        for (auto it : mp1) {
            int freq = it.second;
            if (freq >= 2) {
                totalelementremoval += freq - 1;
                mp1[it.first] = 1;
            }
        }
        if (totalelementremoval < (k / 2)) {

            for (auto it : s) {
                if (mp1[it] > 0) {
                    totalelementremoval += 1;
                    mp1[it] = 0;
                }
                if (totalelementremoval == k / 2)
                    break;
            }
            if (totalelementremoval < (k / 2)) {

                for (auto it : mp1) {
                    if (it.second >= 1) {
                        totalelementremoval += 1;
                        mp1[it.first] = 0;
                        if (totalelementremoval == (k / 2))
                            break;
                    }
                }
            }
        }

        for(auto it:mp1){
            if(it.second>0)
            cout<<it.first<<" ";
        }
        cout<<"first map"<<endl;

        cout << totalelementremoval << endl;

        int totalelementremoval2 = 0;

        for (auto it : mp2) {
            int freq = it.second;
            if (freq >= 2) {
                totalelementremoval2 += freq - 1;
                mp2[it.first] = 1;
            }
        }
        cout << totalelementremoval2 << endl;

        if (totalelementremoval2 < (k / 2)) {

            for (auto it : s) {

                if (mp1[it]>0 and mp2[it] > 0) {
                    totalelementremoval2 += 1;
                    mp2[it] = 0;
                    if (totalelementremoval2 == k / 2)
                        break;
                }
            }

            if (totalelementremoval2 < (k / 2)) {

                for (auto it : mp2) {
                    if (it.second >= 1) {
                        totalelementremoval2 += 1;
                        mp2[it.first] = 0;
                        if (totalelementremoval2 == (k / 2))
                            break;
                    }
                }
            }
        }
        
        for(auto it:mp2){
            if(it.second>=1)
        cout<<it.first<<" ";

        }

        cout<<"secondmap"<<endl;


        cout << totalelementremoval2 << endl;

        unordered_set<int> s1;
        for (auto it : mp1) {
            if (it.second > 0)
                s1.insert(it.first);
        }
        for (auto it : mp2) {
            if (it.second > 0)
                s1.insert(it.first);
        }
        return s1.size();
    }
};