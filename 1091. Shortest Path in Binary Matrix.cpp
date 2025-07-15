class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    bool isSafe(int x, int y, int n){
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // Priority Queue {dist, {x,y}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // distance vector stores min-distance to reach (i,j)th node
        vector<vector<int>> distance(n, vector<int> (n, INT_MAX));

        // Initial Values
        pq.push({0, {0,0}});
        distance[0][0] = 0;

        // Traverse the grid
        while(!pq.empty()){
            auto cell = pq.top();
            pq.pop();

            int d = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            // Explore neighbours of (x,y)th node
            for(auto& dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_, n) && grid[x_][y_] == 0){
                    if(d+1 < distance[x_][y_]){
                        pq.push({d+1, {x_, y_}});
                        distance[x_][y_] = d+1;
                    }
                }
            }
        }

        // If last node is not reached, i.e. INT_MAX, return -1
        if(distance[n-1][n-1] == INT_MAX) return -1; 

        return distance[n-1][n-1]+1;
    }
};
