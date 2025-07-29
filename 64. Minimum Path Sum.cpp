// Recursion TC: O(2^(m+n)) SC: O(m+n)
class Solution {
public:
    void getPathSum(vector<vector<int>>& grid, int i, int j, int m, int n, int currSum, int& minSum){
        // Out of Bounds
        if(i >= m || j >= n) return;

        currSum += grid[i][j];

        // Reached Path
        if(i == m-1 && j == n-1){
            minSum = min(minSum, currSum);
            return;
        }

        // Go Right
        getPathSum(grid, i, j+1, m, n, currSum, minSum);

        // Go Down
        getPathSum(grid, i+1, j, m, n, currSum, minSum);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int minSum = INT_MAX;
        getPathSum(grid, 0, 0, m, n, 0, minSum);

        return minSum;
    }
};

// Memoization TC: O(m*n) SC: O(m*n) + O(m+n) Recursion Space
class Solution {
public:
    int getPathSum(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& dp){
        // Out of Bounds
        if(i >= m || j >= n) return INT_MAX;

        // Reached Destination
        if(i == m-1 && j == n-1) return grid[i][j];
        
        // If value is known, return that value
        if(dp[i][j] != -1) return dp[i][j];


        // Go Right
        int right = getPathSum(grid, i, j+1, m, n, dp);

        // Go Down
        int down = getPathSum(grid, i+1, j, m, n, dp);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return getPathSum(grid, 0, 0, m, n, dp);
    }
};

// Tabulation TC: O(m*n) SC: O(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        // Initialization
        dp[0][0] = grid[0][0];

        // First row
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];

        // First column
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        // Fill up remaining matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int right = dp[i][j - 1];
                int down = dp[i - 1][j];

                dp[i][j] = grid[i][j] + min(right, down);
            }
        }

        return dp[m-1][n-1];
    }
};

// Space Optimization TC: O(m*n) SC: O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n);

        // Initialization
        dp[0] = grid[0][0];

        // Fill first row
        for(int j=1; j<n; j++) dp[j] = dp[j-1] + grid[0][j];

        // Fill up remaining matrix
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }

        return dp[n-1];
    }
};
