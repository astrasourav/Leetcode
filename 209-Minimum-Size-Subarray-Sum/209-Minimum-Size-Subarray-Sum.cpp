class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int l = 0, r = 0, sum = 0, window = INT_MAX;

        for (r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum >= target) {
                window = min(window, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        if (window == INT_MAX) {
            return 0;
        } else {
            return window;
        }
    }
};

