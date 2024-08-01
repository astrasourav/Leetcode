#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);  // Initialize ans with the size of temperatures and fill with 0s
        stack<int> st;  // Stack to keep track of indices of temperatures

        for (int i = n - 1; i >= 0; --i) {
           
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            st.push(i);
        }

        return ans;
    }
};

