class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int x, int y, int rows, int cols){
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        // Push sources into the queue
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int time = 0;

        // Check whether all oranges can be rotten or not
        while(!q.empty() && fresh > 0){
            int size = q.size();

            for(int i=0; i<size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                // Explore all directions
                for(auto& dir:directions){
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_, y_, rows, cols) && grid[x_][y_] == 1){
                        fresh--;
                        grid[x_][y_] = 2;
                        q.push({x_, y_});
                    }
                }
            }

            time++;
        }

        return (fresh == 0) ? time : -1;
    }
};
