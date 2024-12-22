class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();

        int start = 0, end = r-1;
        while(start <= end){
            int midRow = start + (end-start)/2;

            if(matrix[midRow][0] <= target && target <= matrix[midRow][c-1]){    // Correct row found
                int s = 0, e = c-1;
                while(s <= e){
                    int midCol = s + (e-s)/2;
                    if(matrix[midRow][midCol] == target) return true;    // Correct column found
                    else if(matrix[midRow][midCol] > target) e = midCol-1;
                    else s = midCol+1;
                }
                return false;
            }
            else if(matrix[midRow][c-1] > target) end = midRow-1;
            else start = midRow+1;
        }

        return false;
    }
};
