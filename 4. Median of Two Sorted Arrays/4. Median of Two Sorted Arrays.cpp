//brute force method 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        // Merge both arrays into one sorted array
        vector<int> merged;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        // Copy any remaining elements from nums1
        while (i < n) {
            merged.push_back(nums1[i]);
            i++;
        }

        // Copy any remaining elements from nums2
        while (j < m) {
            merged.push_back(nums2[j]);
            j++;
        }

        // Calculate the median
        int size = merged.size();
        double median;
        if (size % 2 == 0) {
            median = (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
        } else {
            median = merged[size / 2];
        }

        return median;
    }
};


//optimal method
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n = nums1.size();
        int m = nums2.size();
        int low = 0, high = n;
        
        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (n + m + 1) / 2 - partition1;
            
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == n) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == m) ? INT_MAX : nums2[partition2];
            
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Found the correct partition
                if ((n + m) % 2 == 0) {
                    return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2;
                } else {
                    return (double)max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // Move left in nums1
                high = partition1 - 1;
            } else {
                // Move right in nums1
                low = partition1 + 1;
            }
        }
        
        throw invalid_argument("Input arrays are not sorted");
    }
};

