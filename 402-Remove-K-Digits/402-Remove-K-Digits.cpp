class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) {
            return "0";
        }

        string ans = "";
        for (int i = 0; i < num.size(); i++) {
            while (k > 0 && ans.size() > 0 && ans.back() > num[i]) {
                ans.pop_back();
                k--;
            }

            // Skip leading zeros
            if (ans.size() == 0 && num[i] == '0') {
                continue;
            }

            ans.push_back(num[i]);
        }

        // Remove remaining characters if k > 0
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        if (ans.empty()) {
            return "0";
        }

        return ans;
    }
};

