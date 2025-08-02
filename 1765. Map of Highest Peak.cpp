class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int x, int y, int rows, int cols){
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();

        vector<vector<int>> heights(rows, vector<int> (cols, 0));

        queue<pair<int, pair<int, int>>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(isWater[i][j] == 1){
                    q.push({0, {i, j}});
                }
            }
        }

        while(!q.empty()){
            int height = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for(auto& dir:directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_, rows, cols) && isWater[x_][y_] == 0){
                    q.push({height+1, {x_, y_}});
                    isWater[x_][y_] = 1;
                    heights[x_][y_] = height+1;
                }
            }
        }

        return heights;
    }
};
