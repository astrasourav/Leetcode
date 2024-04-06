//Solution 1
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.size() == 0) {
            return "";
        }

        string ans="";
        stack<char> st;

        for (int i=0; i<s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                ans+=s[i];
            } else if (s[i] == '(') {
                st.push(s[i]);
                ans+=s[i];
            } else  if (s[i] == ')'){
                if (st.empty()) {
                    continue;
                } else {
                    st.pop();
                    ans+=s[i];
                }
            }
        }
        while (!st.empty()) {
            ans.erase(ans.find_last_of('('), 1);
            st.pop();
        }
        return ans;
    }
};


//Solution 2
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.size() == 0) {
            return "";
        }

        string ans="";
        stack<int> st;

        for (int i=0; i<s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                ans+=s[i];
            } else if (s[i] == '(') {
                st.push(ans.size());
                ans+=s[i];
            } else  if (s[i] == ')'){
                if (st.empty()) {
                    continue;
                } else {
                    st.pop();
                    ans+=s[i];
                }
            }
        }

        while (!st.empty()) {
            ans.erase(st.top(), 1);
            st.pop();
        }
        return ans;
    }
};
