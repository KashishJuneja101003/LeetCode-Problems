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
