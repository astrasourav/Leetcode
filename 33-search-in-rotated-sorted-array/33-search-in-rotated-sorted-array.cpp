//Code 1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0, high = nums.size()-1;

        while (low <=high) {
            int mid = (low+high)/2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target <= nums[mid]) {
                    high = mid -1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid+1;
                } else {
                    high = mid - 1;
                }
            }

        }

        return -1;
    }
};

//Code 2


class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;
        
        while (low <= high) {
            int mid = low + (high -low)/2;
            
            if (arr[low] <= arr[high]) {
                ans = min (ans, arr[low]);
                break;
            }
            
            if (arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]);
                low = mid+1;
            } else {
                ans = min(ans, arr[mid]);
                high = mid -1;
            }
        }
        
        return ans;
    }
};

