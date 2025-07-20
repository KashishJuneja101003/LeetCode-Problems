class Solution {
public:
    long long DFS(vector<vector<int>>& grid, int i, int j){
        int rows = grid.size();
        int cols = grid[0].size();

        if(i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) return 0; 

        int val = grid[i][j];
        grid[i][j] = 0;

        return (long long) val + DFS(grid, i-1, j) + DFS(grid, i+1, j) + DFS(grid, i, j-1) + DFS(grid, i, j+1);
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] != 0){
                    long long currSum = DFS(grid, i, j);

                    if(currSum % k == 0) count++;
                }
            }
        }

        return count;
    }
};
