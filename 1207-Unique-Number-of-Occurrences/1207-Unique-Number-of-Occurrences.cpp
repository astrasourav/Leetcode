class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        if (arr.empty()) {
            return false;
        }

        unordered_map<int,int>mp;
        unordered_set<int>st;
        for (auto it:arr) {
            mp[it]++;
        }

        for (auto it: mp) {
            if (!st.insert(it.second).second) {
                return false;
            }
        }

        return true;
    }
};
