// Recursion TC: O(2^(m+n)) 
class Solution {
public:
    int LCS(string s1, int i1, string s2, int i2){
        if(i1 < 0 || i2 < 0) return 0;

        int match = 0;
        int notMatch = 0;

        if(s1[i1] == s2[i2]){
            match = 1 + LCS(s1, i1-1, s2, i2-1);
        } else{
            int reduce1 = LCS(s1, i1-1, s2, i2);
            int reduce2 = LCS(s1, i1, s2, i2-1);

            notMatch = max(reduce1, reduce2);
        }

        return max(match, notMatch);
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();

        return LCS(s, n-1, s2, n-1);
    }
};

// Memoization TC: O(n^2) SC: O(n^2) + O(2n)
class Solution {
public:
    int LCS(string s1, int i1, string s2, int i2, vector<vector<int>>& dp){
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];

        int match = 0;
        int notMatch = 0;

        if(s1[i1] == s2[i2]){
            match = 1 + LCS(s1, i1-1, s2, i2-1, dp);
        } else{
            int reduce1 = LCS(s1, i1-1, s2, i2, dp);
            int reduce2 = LCS(s1, i1, s2, i2-1, dp);

            notMatch = max(reduce1, reduce2);
        }

        return dp[i1][i2] = max(match, notMatch);
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();

        vector<vector<int>> dp(n, vector<int> (n, -1));

        return LCS(s, n-1, s2, n-1, dp);
    }
};

// Tabulation TC: O(n^2) SC: O(n^2)
class Solution {
public:
    int LCS(string s1, string s2, int n, vector<vector<int>>& dp) {

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int match = 0;
                int notMatch = 0;
                if (s1[i - 1] == s2[j - 1]) {
                    match = 1 + dp[i - 1][j - 1];
                } else {
                    int reduce1 = dp[i - 1][j];
                    int reduce2 = dp[i][j - 1];

                    notMatch = max(reduce1, reduce2);
                }

                dp[i][j] = max(match, notMatch);
            }
        }

        return dp[n][n];
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        return LCS(s, s2, n, dp);
    }
};
