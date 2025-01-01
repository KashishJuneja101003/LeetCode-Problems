class Solution {
public:
    int row = 0, col = 0;
    bool isSafe(vector<vector<int>>& grid, int n, int curr){
        if(row-2 >= 0 && col+1 < n && grid[row-2][col+1] == curr+1) {
            row -= 2; col += 1; 
            // cout<<grid[row][col]<<" "; cout<<"("<<row<<", "<<col<<")\n"; 
            return true;
        }

        if(row-2 >= 0 && col-1 >= 0 && grid[row-2][col-1] == curr+1) {
            row -= 2; col -= 1; 
            // cout<<grid[row][col]<<" "; cout<<"("<<row<<", "<<col<<")\n"; 
            return true;
        }

        if(row-1 >= 0 && col+2 < n && grid[row-1][col+2] == curr+1) {
            row -= 1; col += 2; 
            // cout<<grid[row][col]<<" "; cout<<"("<<row<<", "<<col<<")\n"; 
            return true;
        }

        if(row-1 >= 0 && col-2 >= 0 && grid[row-1][col-2] == curr+1) {
            row -= 1; col -= 2; 
            // cout<<grid[row][col]<<" "; cout<<"("<<row<<", "<<col<<")\n"; 
            return true;
        }
        
        if(row+1 < n && col+2 < n && grid[row+1][col+2] == curr+1) {
            row += 1; col += 2; 
            // cout<<grid[row][col]<<" "; cout<<"("<<row<<", "<<col<<")\n"; 
            return true;
        }

        if(row+1 < n && col-2 >= 0 && grid[row+1][col-2] == curr+1) {
            row += 1; col -= 2; 
            // cout<<grid[row][col]<<" "; cout<<"("<<row<<", "<<col<<")\n"; 
            return true;
        }
        
        if(row+2 < n && col+1 < n && grid[row+2][col+1] == curr+1) {
            row += 2; col += 1; 
            // cout<<grid[row][col]<<" "; cout<<"("<<row<<", "<<col<<")\n";
            return true;
        }

        if(row+2 < n && col-1 >= 0 && grid[row+2][col-1] == curr+1) {
            row += 2; col -= 1; 
            // cout<<grid[row][col]<<" "; cout<<"("<<row<<", "<<col<<")\n"; 
            return true;
        }

        return false;
    }

    bool helper(vector<vector<int>>& grid, int i, int n){
        if(i == n*n-1) return true;

        if(isSafe(grid, n, i)){
            return helper(grid, i+1, n);
        }
        
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[row][col] != 0) return false;

        // cout<<grid[row][col]<<" "; cout<<"("<<row<<", "<<col<<")\n";
        
        return helper(grid, 0, grid.size());
    }
};
