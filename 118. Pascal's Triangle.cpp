class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1,1}};

        vector<vector<int>> mat;
        mat.push_back({1});
        mat.push_back({1,1});

        for(int i=2; i<numRows; i++){
            vector<int> temp(i+1);
            temp[0] = temp[i] = 1;
            for(int j = 1; j < i; j++){
                temp[j] = mat[i-1][j-1] + mat[i-1][j];
            }
            mat.push_back(temp);
        }

        return mat;
    }
};
