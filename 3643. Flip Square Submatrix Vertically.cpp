// TC: O(rows*cols), rows = (x+k-1)/2, cols = y, SC: O(1)
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int r1 = x;
        int r2 = x+k-1;

        while(r1 < r2){
            int c1 = y;
            for(int i=0; i<k; i++){
                swap(grid[r1][c1], grid[r2][c1]);
                c1++;
            }
            r1++; r2--;
        }

        return grid;
    }
};
