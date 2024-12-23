class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();

        int a,b, sum=0;
        unordered_set<int> set;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum += grid[i][j];
                if(set.find(grid[i][j]) != set.end()){
                    a = grid[i][j];
                }
                set.insert(grid[i][j]);
            }
        }
        b = (n*n)*((n*n)+1)/2 + a - sum;
        
        return {a,b};
    }
};
