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
        int n = nums.size();

        if (n==0) {
            return 0;
        }

        if (n == 1) {
            return nums[0];
        }

        return max(getMax(nums, 0, n - 2), getMax(nums, 1, n - 1));
    }
};