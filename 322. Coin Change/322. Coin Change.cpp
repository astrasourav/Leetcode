class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) {
            return 0;
        }

        //make dp array
        vector<int> dp(amount+1);

        for (int i=1; i<=amount; i++) {
            dp[i] = INT_MAX;

            for (auto it: coins) {
                if (it <= i && dp[i - it] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - it]);
                }
            }
        }

        if (dp[amount] == INT_MAX) {
            return -1;
        } 

        return dp[amount];
    }
};
