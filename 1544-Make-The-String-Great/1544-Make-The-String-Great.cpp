class Solution {
public:
    string makeGood(string s) {
        if (s.length()==0){
            return "";
        }
        string res;
        stack<char> st;

        for (int i=0; i<s.length(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                char temp = st.top();
                if (abs(temp - s[i]) == 32) {//if characters are same and one of them is in uppercse then there abs will be always 32.
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());

        return res;
    }
};
