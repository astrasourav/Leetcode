class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        stack<int> st;
        int maxi = 0;
        int n = heights.size();
        for (int i=0; i<=n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;

                if (st.empty()) {
                    width = i;
                } else {
                    width = (i - st.top()- 1);
                }
                maxi = max(maxi, height* width);
            }
            st.push(i);
        }

        return maxi;
    }
};
