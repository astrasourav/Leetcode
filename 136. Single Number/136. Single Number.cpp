class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int  xorr = 0;
        for (int i=0; i<nums.size(); i++) {
            xorr = xorr^nums[i];
        }

        return xorr;


    }
};
