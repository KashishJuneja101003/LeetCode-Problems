// Recursion TC: O(2^(m+n)) SC: O(m+n)
class Solution {
public:
    int canReach(int i, int j, int m, int n){
        // Out of bounds
        if(i >= m || j >= n) return 0;

        // Reached destination 
        if(i == m-1 && j == n-1) return 1;

        // Explore paths
        int right = canReach(i, j+1, m, n);
        int down = canReach(i+1, j, m, n);

        return right + down;
    }
    int uniquePaths(int m, int n) {
        return canReach(0, 0, m, n);
    }
};

// Memoization TC: O(m*n) SC: O(m*n) - DP Table + O(m+n) - Recursion Stack
class Solution {
public:
    int canReach(int i, int j, int m, int n, vector<vector<int>>& dp){
        // Out of bounds
        if(i >= m || j >= n) return 0;

        // Reached destination 
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        // Explore paths
        int right = canReach(i, j+1, m, n, dp);
        int down = canReach(i+1, j, m, n, dp);

        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        return canReach(0, 0, m, n, dp);
    }
};

// Tabulation TC: O(m*n) SC: O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1)); 

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// Space Optimization TC: O(m*n) SC: O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1); 

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};
