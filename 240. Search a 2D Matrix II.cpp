class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows = mat.size(), cols = mat[0].size(), r = 0, c = cols-1;

        while(r < rows && c >= 0){
            if(target == mat[r][c]) return true;
            else if(target < mat[r][c]) c--;
            else r++;
        }

        return false;
    }
};
