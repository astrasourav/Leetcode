class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if (intervals.empty()) {
            return ans;
        }

        // Sort intervals based on the starting times
        sort(intervals.begin(), intervals.end());

        // Iterate through each interval
        for (const auto& interval : intervals) {
            // If ans is empty or the current interval doesn't overlap with the last one in ans
            if (ans.empty() || interval[0] > ans.back()[1]) {
                ans.push_back(interval);
            } else {
                // If it overlaps, merge the intervals by updating the end time
                ans.back()[1] = max(interval[1], ans.back()[1]);
            }
        }

        return ans;
    }
};

