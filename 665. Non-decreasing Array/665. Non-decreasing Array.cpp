class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.empty() == true || nums.size() == 1) {
            return true;
        }

        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                cnt++;

                if (cnt > 1) {
                    return false;
                }

                if (i > 0 && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] =
                        nums[i]; // Modify nums[i + 1] to maintain order
                } else {
                    nums[i] = nums[i + 1]; // Modify nums[i]
                }
            }
        }

        return true;
    }
};
