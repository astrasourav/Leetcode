class Solution {
public:
    void fun(int ind, string s, vector<vector<string>>& ans, vector<string>& path) {
        if (ind == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i=ind; i<s.size(); i++) {
            if (ispalindrome(s, ind, i)) {
                path.push_back(s.substr(ind, i - ind + 1));
                fun(i+1,s,ans,path);
                path.pop_back();
            }
        }
    }

    bool ispalindrome(string s, int start, int end) {
        while(start<end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        fun(0, s, ans, path);
        return ans;
    }
};
