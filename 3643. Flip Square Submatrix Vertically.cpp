// TC: O(k^2) SC: O(1)
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int r1 = x;
        int r2 = x + k - 1;

        while (r1 < r2) {
            for (int c = y; c < y+k; c++) {
                swap(grid[r1][c], grid[r2][c]);
            }
            r1++;
            r2--;
        }

        return grid;
    }
};
