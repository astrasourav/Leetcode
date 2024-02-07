class Solution {
public:
    string frequencySort(string s) {
        // string ans="";
        if(s.size() == 0) {
            return s;
        }

        vector<int>freq(128, 0);
        for (auto it : s) {
            freq[it]++;
        }

        auto cmp = [&](char a, char b) {
            if (freq[a] == freq[b]) {
                return a < b;
            } else {
                return freq[a]>freq[b];
            }
        };

        sort(s.begin(), s.end(), cmp);
        return s;

    }
};
