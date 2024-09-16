class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) {
            return"";
        }

        int n = strs.size();
        string s="";

        for(int i=0; i<n; i++) {
            string str = strs[i];
            s += to_string(str.size()) + '#' + str;
        }

        return s;
    }

    vector<string> decode(string s) {
        if (s.length() == 0) {
            return {};
        }

        vector<string> ans;
        int n = s.size();
        int i=0;

        while (i < n) {
            int j = i;
            
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            string str = s.substr(j + 1, len);
            ans.push_back(str);
            i= j+ 1+ len;
        }

        return ans;
    }
};

