// TC: O(m*n) SC: O(m*n)
class Solution {
public:
    void DFS(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited){
        int rows = grid.size();
        int cols = grid[0].size();

        // Checks
        if(r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || grid[r][c] == '0') return;

        visited[r][c] = true;

        DFS(grid, r-1, c, visited);
        DFS(grid, r+1, c, visited);
        DFS(grid, r, c-1, visited);
        DFS(grid, r, c+1, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));

        int numIslands = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    DFS(grid, i, j, visited);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
};
