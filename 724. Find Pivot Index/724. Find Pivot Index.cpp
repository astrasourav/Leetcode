class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }

        int sum = 0;
        int ls = 0;
        for (int i=0; i<nums.size(); i++) {
            sum+= nums[i];
        }

        for (int i=0; i<nums.size(); i++) {
            int rs = sum - ls - nums[i];
            if (ls == rs) {
                return i;
            }

            ls += nums[i];
        }

        return -1;
    }
};
