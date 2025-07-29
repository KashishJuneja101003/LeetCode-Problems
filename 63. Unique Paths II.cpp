// Recursion TC: O(2^(m+n)) SC: O(m+n)
class Solution {
public:
    int canReach(vector<vector<int>>& obstacleGrid, int i, int j, int m, int n){
        // Out of bounds
        if(i >= m || j >= n) return 0;

        // Reached destination 
        if(i == m-1 && j == n-1) return 1;

        // If obstacle return
        if(obstacleGrid[i][j] == 1) return 0;

        // Explore paths
        int right = canReach(obstacleGrid, i, j+1, m, n);
        int down = canReach(obstacleGrid, i+1, j, m, n);

        return right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return canReach(obstacleGrid, 0, 0, m, n);
    }
};

// Memoization TC: O(m*n) SC: O(m*n) + O(m+n)
class Solution {
public:
    int canReach(vector<vector<int>>& obstacleGrid, int i, int j, int m, int n, vector<vector<int>>& dp){
        // Out of bounds
        if(i >= m || j >= n) return 0;

        // If obstacle return
        if(obstacleGrid[i][j] == 1) return 0;

        // Reached destination 
        if(i == m-1 && j == n-1) return 1;

        // If known, return 
        if(dp[i][j] != -1) return dp[i][j];

        // Explore paths
        int right = canReach(obstacleGrid, i, j+1, m, n, dp);
        int down = canReach(obstacleGrid, i+1, j, m, n, dp);

        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));
        return canReach(obstacleGrid, 0, 0, m, n, dp);
    }
};

// Tabulation TC: O(m*n) SC: O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // obstacle at top-left or bottom-right
        if(obstacleGrid[0][0] != 0 || obstacleGrid[m-1][n-1] != 0) return 0;

        // Initialization
        dp[0][0] = 1;

        // First row
        for(int j=1; j<n; j++){
            if(obstacleGrid[0][j] == 0) dp[0][j] = 1;
            else break;
        }

        // First column
        for(int i=1; i<m; i++){
            if(obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
