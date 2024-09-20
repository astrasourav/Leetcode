class Solution {
public:
    int getMax(vector<int>& nums, int start, int end) {
        int prev1 = 0; // Max money if the previous house is not robbed
        int prev2 = 0;

        for (int i = start; i <= end; i++) {
            int current = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return nums[0];
        }

        int n = nums.size();

        return max(getMax(nums, 0, n - 2), getMax(nums, 1, n - 1));
    }
};