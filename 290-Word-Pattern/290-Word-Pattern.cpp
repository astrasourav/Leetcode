class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string temp = "";
        int i = 0;
        while (i < s.size()) {
            if (s[i] != ' ') {
                temp += s[i];
            } else {
                v.push_back(temp);
                temp = "";
            }
            i++;
        }
        v.push_back(temp);

        if (pattern.size() != v.size()) {
            return false;
        }

        unordered_map<char, string> m;
        set<string> st;

        for (int i = 0; i < pattern.size(); i++) {
            if (m.find(pattern[i]) !=
                m.end()) { // finding the character in hashmap
                if (m[pattern[i]] != v[i]) {
                    return false;
                }
            } else {
                if (st.count(v[i]) > 0) {
                    return false;
                }
                m[pattern[i]] = v[i];
                st.insert(v[i]);
            }
        }

        return true;
    }
};
