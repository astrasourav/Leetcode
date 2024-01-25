class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>fr;

        for (auto it: s) {
            fr[it]++;
        }

        for (auto it: t) {
            fr[it]--;
        }

        for (auto it : fr) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};
