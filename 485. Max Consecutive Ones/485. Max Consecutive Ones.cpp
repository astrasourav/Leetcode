class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) return 0;

        int res = 0;
        int cnt=0;

        for (int i=0 ;i<nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
                res = max(cnt, res);
            } else {
                cnt = 0;
            }
        }

        return res;
    }
}; 
