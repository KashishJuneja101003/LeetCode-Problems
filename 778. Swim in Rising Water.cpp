// TC: O(n² log n²) ≈ O(n² log n) SC: O(n²)
class Solution {
public:
    int n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isSafe(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        // Min-heap: stores {time, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int time = top[0];
            int x = top[1];
            int y = top[2];

            // If we reached the destination
            if (x == n - 1 && y == n - 1)
                return time;

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (isSafe(nx, ny) && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    // The time needed to reach (nx, ny) is the max of current water level and grid[nx][ny]
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                }
            }
        }

        return -1; // Should never reach here
    }
};
