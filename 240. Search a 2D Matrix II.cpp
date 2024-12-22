class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows = mat.size(), cols = mat[0].size(), r = rows-1, c = 0;

        while(r >= 0 && c < cols){
            if(target == mat[r][c]) return true;
            else if(target < mat[r][c]) r--;
            else c++;
        }

        return false;
    }
};
