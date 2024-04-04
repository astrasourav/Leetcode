class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        int cnt = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                cnt++;
                if (cnt > ans) {
                    ans = cnt;
                }
            } else if (s[i] == ')') {
                st.pop();
                cnt--;
            } else {
                continue;
            }
        }

        return ans;
    }
};
