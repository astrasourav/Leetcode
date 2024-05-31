class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        int prefix = 1, suffix = 1, ans = INT_MIN;

        for (int i=0; i<n; i++) {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n-1-i];

            ans = max(ans, max(prefix, suffix));
        }

        return ans;
    }
};
