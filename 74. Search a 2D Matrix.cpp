class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size(), idx = -1;

        for(int i=0; i<r; i++){
            if(matrix[i][c-1] >= target){
                idx = i; break;
            }
        }

        if(idx == -1) return false;

        for(int j=0; j<c; j++){
            if(matrix[idx][j] == target) return true;
        }

        return false;
    }
};
