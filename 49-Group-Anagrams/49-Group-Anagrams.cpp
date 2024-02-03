class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        if (strs.size() == 0){
            return ans;
        }

        unordered_map<string, vector<string>>m;
        for (auto it: strs) {
            string word = it;
            sort(word.begin(), word.end());
            m[word].push_back(it);
        }

        for (auto it : m) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
