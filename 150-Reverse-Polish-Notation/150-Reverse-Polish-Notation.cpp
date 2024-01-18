class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n = tokens.size();
        
        for (auto i: tokens) {
            if ( (i == "+") || (i == "-") || (i == "*") || (i == "/")) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (i == "+") st.push(a+b);
                if (i == "*") st.push(a*b);
                if (i == "-") st.push(a-b);
                if (i == "/") st.push(a/b);
            } else {
                st.push(stoi(i));
            }
        }
        
        return st.top();
    }
};
