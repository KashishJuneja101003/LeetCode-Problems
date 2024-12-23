class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int minRow = 0, minCol = 0, maxRow = m - 1, maxCol = n - 1;
        int i = 0, j = 0;

        vector<int> seq;

        while (minRow <= maxRow && minCol <= maxCol) {
            // Traverse from left to right
            while (j <= maxCol) seq.push_back(matrix[i][j++]);
            minRow++; i++; j--;

            // Traverse from top to bottom
            while (i <= maxRow) seq.push_back(matrix[i++][j]);
            maxCol--; j--; i--;

            // Traverse from right to left (if still in bounds)
            if (minRow <= maxRow) {
                while (j >= minCol) seq.push_back(matrix[i][j--]);
                maxRow--; i--; j++;
            }

            // Traverse from bottom to top (if still in bounds)
            if (minCol <= maxCol) {
                while (i >= minRow) seq.push_back(matrix[i--][j]);
                minCol++; i++; j++;
            }
        }

        return seq;
    }
};
