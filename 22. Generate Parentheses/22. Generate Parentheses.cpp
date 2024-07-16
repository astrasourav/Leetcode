class Solution {
public:
    void ans (vector<string>& v, int n, int oc, int cc, string s) {
        if (oc == n && cc == n) {
            v.push_back(s);
        }

        if (oc < n) {
            ans(v, n, oc+1, cc, s+"(");
        }

        if (cc < oc) {
            ans(v, n, oc, cc+1, s+")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int oc = 0, cc = 0;

        ans(v, n, oc, cc, "");
        return v;
    }
};
