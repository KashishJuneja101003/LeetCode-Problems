class Solution {
public:
    void getCost(vector<vector<int>>& grid, int x, int y, int k, int curr, int& minCost) {
        int m = grid.size();
        int n = grid[0].size();

        // Reached Destination
        if (x == m - 1 && y == n - 1) {
            minCost = min(minCost, curr);
            return;
        }

        // Move Down
        if (x + 1 < m)
            getCost(grid, x + 1, y, k, curr + grid[x + 1][y], minCost);
        // Move Right
        if (y + 1 < n)
            getCost(grid, x, y + 1, k, curr + grid[x][y + 1], minCost);

        // Teleport
        if (k > 0) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (!(x == i && y == j) && grid[i][j] <= grid[x][y]) {
                        getCost(grid, i, j, k - 1, curr, minCost);
                    }
                }
            }
        }
    }

    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(k+1, INT_MAX)));
        int minCost = INT_MAX;
        getCost(grid, 0, 0, k, 0, minCost);
        return minCost;
    }
};
