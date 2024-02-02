class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        unordered_set<int>st;
        int longest = 1;
        for (int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }

        for (auto it: st) {
            if (st.find(it - 1) == st.end()) {//(it-1) element is not present
                int count = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x++;
                    count++;
                }
                longest = max(longest, count);
            }
        }

        return longest;
    }
};
