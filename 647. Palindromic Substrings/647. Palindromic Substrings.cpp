class Solution {
public:
    int expand(string& s, int l, int r) {
        int cnt = 0;
        // Proper bounds check and comparison of characters
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    
    int countSubstrings(string s) {
        if (s.length() == 0) {
            return 0;
        }

        int res = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // Check for odd-length palindromes (centered at a single character)
            res += expand(s, i, i);
            // Check for even-length palindromes (centered between two characters)
            res += expand(s, i, i + 1);
        }

        return res;
    }
};

