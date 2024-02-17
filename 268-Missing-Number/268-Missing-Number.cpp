class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        unordered_map<int, int>mp;
        for (auto it: nums) {
            mp[it]++;
        }

        for (int i=0; i<=n; i++) {
            if (!mp.count(i)) {
                return i;
            }
        }

        return 0;
    }
};
