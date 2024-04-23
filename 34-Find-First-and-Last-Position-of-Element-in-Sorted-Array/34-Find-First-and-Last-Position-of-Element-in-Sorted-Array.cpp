class Solution {
public:
    int findLeftBound(vector<int>& nums, int target) {
        int index = -1;
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                index = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return index;
    }

    int findRightBound(vector<int>& nums, int target) {
        int index = -1;
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                index = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeftBound(nums, target);
        int right = findRightBound(nums, target);

        return {left, right};
    }
};
