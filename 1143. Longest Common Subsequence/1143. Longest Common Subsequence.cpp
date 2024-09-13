class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // Initialize two vectors to store the current and previous rows of the
        // DP table
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        // Base case is covered as we have initialized the prev and cur vectors
        // to 0.

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    cur[ind2] =
                        1 + prev[ind2 -
                                 1]; // Characters match, increment LCS length
                else
                    cur[ind2] =
                        max(prev[ind2],
                            cur[ind2 - 1]); // Characters don't match, consider
                                            // the maximum from above or left
            }
            prev = cur; // Update the previous row with the current row
        }

        return prev[m]; // Return the length of the Longest Common Subsequence
    }
};
