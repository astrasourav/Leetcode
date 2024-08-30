class Solution {
public:
    int expand(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int n = s.length();
        int start = 0, maxLen = 1;

        for (int i=0; i<n; i++) {
            int odd = expand(s, i, i);//odd
            int even = expand(s, i, i+1);//even

            int len = max(odd, even);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
