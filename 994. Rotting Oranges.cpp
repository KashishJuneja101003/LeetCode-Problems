class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int x, int y, int rows, int cols){
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;

        int rows = grid.size();
        int cols = grid[0].size();

        // Pushing rotten oranges (sources) to the queue
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2) q.push({0, {i, j}});
            }
        }

        int minTime = 0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int time = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            minTime = time;

            for(auto& dir:directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_, rows, cols) && grid[x_][y_] == 1){
                    q.push({time+1, {x_, y_}});
                    grid[x_][y_] = 2;
                }
            }
        }

        // Check if all oranges are rotten or not
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                // Fresh orange found, return -1
                if(grid[i][j] == 1) return -1;
            }
        }

        return minTime;
    }
};
