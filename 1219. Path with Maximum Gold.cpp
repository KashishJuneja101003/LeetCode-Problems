// TC: O(k * 4^k) SC: O(k)
class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int x, int y, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return x >= 0 && y >= 0 && x < m && y < n;
    }

    int getAmt(vector<vector<int>>& grid, int x, int y) {
        int currGold = grid[x][y];
        int maxAmt = 0;

        grid[x][y] = 0; // Mark visited

        for (auto& dir : directions) {
            int x_ = x + dir[0];
            int y_ = y + dir[1];

            if (isSafe(x_, y_, grid) && grid[x_][y_] != 0) {
                maxAmt = max(maxAmt, getAmt(grid, x_, y_));
            }
        }

        // Backtrack
        grid[x][y] = currGold;

        return currGold + maxAmt;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxAmt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    maxAmt = max(maxAmt, getAmt(grid, i, j));
                }
            }
        }

        return maxAmt;
    }
};
