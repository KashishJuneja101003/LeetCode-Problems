class Solution {
public:
    int DFS(vector<vector<int>>& grid, int r, int c,
            vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Checks
        if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || grid[r][c] == 0)
            return 0;

        visited[r][c] = true;

        int up = DFS(grid, r - 1, c, visited);
        int down = DFS(grid, r + 1, c, visited);
        int left = DFS(grid, r, c - 1, visited);
        int right = DFS(grid, r, c + 1, visited);

        return 1 + up + down + left + right;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int maxComponents = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int components = DFS(grid, i, j, visited);
                    maxComponents = max(maxComponents, components);
                }
            }
        }

        return maxComponents;
    }
};
