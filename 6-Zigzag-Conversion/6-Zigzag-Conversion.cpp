class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty()) {
            return "";
        }

        if (numRows == 1) {
            return s;
        }

        vector<string>ans(numRows);
        bool flag = false;
        int i=0;

        for (auto ch: s) {
            ans[i] += ch;
            if (i == 0 || i == numRows - 1) {
                flag = !flag;
            }
            if (flag) {
                i++;
            } else {
                i--;
            }
        }

        string zigzag = "";
        for (auto it: ans) {
            zigzag += it;
        }
        return zigzag;
    }
};
