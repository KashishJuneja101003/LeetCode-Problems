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

    int longestCommonSubsequence(string text1, string text2) {
        return LCS(text1, text1.size()-1, text2, text2.size()-1);
    }
};

// Memoization TC: O(m*n) SC: O(m*n) + O(m+n)
class Solution {
public:
    int LCS(string s1, int i1, string s2, int i2, vector<vector<int>> dp){
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

    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();

        vector<vector<int>> dp(size1, vector<int> (size2, -1));
        return LCS(text1, size1-1, text2, size2-1, dp);
    }
};

// Tabulation TC: O(m*n) SC: O(m*n)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                int match = 0;
                int notMatch = 0;
                if (text1[i-1] == text2[j-1]) {
                    match = 1 + dp[i - 1][j - 1];
                } else {
                    int reduce1 = dp[i - 1][j];
                    int reduce2 = dp[i][j - 1];

                    notMatch = max(reduce1, reduce2);
                }
                dp[i][j] = max(match, notMatch);
            }
        }

        return dp[n1][n2];
    }
};
