class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int ele = nums[i];
            

            if (ele >= 1 && ele <= n) {
                int chair = ele - 1;
                if (nums[chair] != ele) {
                    swap(nums[chair], nums[i]);
                    i--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (i + 1 != nums[i]) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
