class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;  // Index for placing the next non-zero element

        // Move all non-zero elements to the front of the array
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[ind] = nums[i];
                ind++;
            }
        }

        // Fill the remaining positions with zeros
        for (int i = ind; i < n; i++) {
            nums[i] = 0;
        }
    }
};

