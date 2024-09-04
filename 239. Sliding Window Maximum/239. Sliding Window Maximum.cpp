class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;  // Deque to store indices of the elements

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices of elements not within the window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove indices of elements that are less than the current element
            // because they are not useful anymore
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // The first element in the deque is the maximum of the current window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

