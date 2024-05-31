class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int ans = INT_MIN;
        int n = nums.size();
        int sum=0;

        for (int i=0; i<n; i++) {
            sum += nums[i];

            if  (sum > ans) {
                ans = sum;
            }
            if (sum < 0) {
                sum = 0;
            }

        }
        return ans;
    }
};
