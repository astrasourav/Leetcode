class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();

        int left = 0;
        int right = n-1;

        while (left <= right) {
            int l = min(height[left], height[right]);
            int b = right - left;
            int area = (l*b);
            ans = max(area, ans);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};
