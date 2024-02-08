class Solution {
public:
    string reverseWords(string s) {
        if ( s.size() == 0) {
            return "";
        }
        
        stack<string>st;
        string res;
        string temp="";
        
        for (int i=0; i<s.size(); i++) {
            // string temp;
            if (s[i] != ' ') {
                temp+=s[i];
            } else {
                if (!temp.empty()) {
                    st.push(temp);
                    temp = "";
                }
            }
        }

        if (!temp.empty()) {
            st.push(temp);
        }
        

        while (!st.empty()) {
            res += st.top()+' ';
            st.pop();
        }

         if (!res.empty()) {
            // Remove the trailing space
            res.pop_back();
        }

        return res;
    }
};
