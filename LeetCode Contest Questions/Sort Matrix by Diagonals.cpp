// You are given an n x n square matrix of integers grid. Return the matrix such that:
// The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
// The diagonals in the top-right triangle are sorted in non-decreasing order.©leetcode

// Example 1:
// Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
// Output: [[8,2,3],[9,6,7],[4,5,1]]

// Example 2:
// Input: grid = [[0,1],[1,2]]
// Output: [[2,1],[1,0]]

// Example 3:
// Input: grid = [[1]]
// Output: [[1]]
// Explanation:
// Diagonals with exactly one element are already in order, so no changes are needed.©leetcode

// Constraints:
// - grid.length == grid[i].length == n
// - 1 <= n <= 10
// -105 <= grid[i][j] <= 105
  
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        // Optimized
        if(n==1) return grid;
        
        vector<vector<bool>>visited(n, vector<bool>(n, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j]){
                    continue;
                }
                
                visited[i][j] = true;
                vector<int>temp;

                if(i < j){
                    for(int a=i, b=j; a<n && b<n; a++, b++){
                        temp.push_back(grid[a][b]);
                        visited[a][b] = true;
                    }
                    sort(temp.begin(), temp.end());
                }

                else{
                    for(int a=i, b=j; a<n && b<n; a++, b++){
                        temp.push_back(grid[a][b]);
                        visited[a][b] = true;
                    }
                    sort(temp.begin(), temp.end(), greater<int>());
                }

                int idx=0;
                for(int a=i, b=j; a<n && b<n; a++, b++, idx++){
                    grid[a][b] = temp[idx];
                }
            }
        }

        return grid;
    }
};
