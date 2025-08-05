// Recursion TC: O(2^n) SC: O(n)
class Solution {
public:
    int getCount(string s, int i, string t, int j){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        int include = 0;
        int exclude = 0;
        
        if(s[i] == t[j]){
            include = getCount(s, i+1, t, j+1);
        } 
        
        exclude = getCount(s, i+1, t, j);
        
        return include + exclude;
    }
    int numDistinct(string s, string t) {
        return getCount(s, 0, t, 0);
    }
};

// Memoization TC: O(n1×n2) SC: O(n1×n2) + O(n1+n2)
class Solution {
public:
    int getCount(string s, int i, string t, int j, vector<vector<int>>& dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int include = 0;
        int exclude = 0;
        
        if(s[i] == t[j]){
            include = getCount(s, i+1, t, j+1, dp);
        } 
        
        exclude = getCount(s, i+1, t, j, dp);
        
        return dp[i][j] = include + exclude;
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        vector<vector<int>> dp(n1, vector<int> (n2, -1));

        return getCount(s, 0, t, 0, dp);
    }
};

// Tabulation TC: O(n1×n2) SC: O(n1×n2)
class Solution {
public:
    int getCount(string s, int n1, string t, int n2,
                 vector<vector<int>>& dp) {
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (long long)dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n1][n2];
    }
    
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Empty string can be formed in one way
        for (int i = 0; i <= n1; i++)
            dp[i][0] = 1;

        return getCount(s, n1, t, n2, dp);
    }
};
