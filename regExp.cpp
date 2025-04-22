class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int t[21][21];

    bool solve(int i, int j, string& text, string& pattern) {
        if (j == pattern.length())
            return i == text.length();
            
        if (t[i][j] != -1) {
            return t[i][j];
        }
        
        bool ans = false;

        bool first_match = (i < text.length() &&
                            (pattern[j] == text[i] || pattern[j] == '.'));

        if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
            ans = (solve(i, j + 2, text, pattern) ||
                   (first_match && solve(i + 1, j, text, pattern)));
        } else {
            ans = first_match && solve(i + 1, j + 1, text, pattern);
        }

        return t[i][j] = ans;
    }
    
    bool isMatch(string text, string pattern) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, text, pattern);
    }
};