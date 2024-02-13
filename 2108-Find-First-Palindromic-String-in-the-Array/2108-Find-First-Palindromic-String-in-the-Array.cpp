class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        if (words.empty()) {
            return "";
        }

        for (auto it : words) {
            string word = it;
            reverse(word.begin(), word.end());
            if (word == it) {
                return it;
            }
        }

        return "";
    }
};
