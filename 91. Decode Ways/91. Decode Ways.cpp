class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0; // No valid encoding for empty string or string starting with '0'
        }

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: one way to decode an empty string
        dp[1] = 1; // One way to decode a non-zero single character

        for (int i = 2; i <= n; i++) {
            // Single character decode (if it's not '0')
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Two-character decode (if it forms a valid number between 10 and 26)
            int twoDigit = stoi(s.substr(i - 2, 2)); // Convert two characters to a number
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
