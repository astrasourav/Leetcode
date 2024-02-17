//This approach is by using hashmap.
//TC -> O(N)
//SC -> O(N)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        vector<int>ans;
        unordered_map<int, int>mp;

        for (auto it: nums) {
            mp[it]++;
        }

        for (int i=1; i<=nums.size(); i++) {
            if (!mp.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};


