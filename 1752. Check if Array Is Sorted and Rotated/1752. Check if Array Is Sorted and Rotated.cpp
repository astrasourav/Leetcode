class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.empty()) return false;

        int cnt = 0;
        int n = nums.size();
        for (int i=1; i<n; i++) {
            if (nums[i-1] > nums[i]) {
                cnt++;
            }
        }

        if (nums[n-1] > nums[0]) {
            cnt++;
        }

        if (cnt > 1) {
            return false;
        }

        return true;
    }
};
