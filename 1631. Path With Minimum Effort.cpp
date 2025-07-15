class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int x, int y, int r, int c){
        return x >= 0 && y >= 0 && x < r && y < c;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}}); // {effort, {x, y}}

        vector<vector<int>> minEffort(rows, vector<int>(cols, INT_MAX));
        minEffort[0][0] = 0;

        while (!pq.empty()) {
            auto [effort, cell] = pq.top(); pq.pop();
            int x = cell.first, y = cell.second;

            if (x == rows - 1 && y == cols - 1)
                return effort;

            for (auto& dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_, rows, cols)) {
                    int currDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxEffort = max(currDiff, effort);

                    if (maxEffort < minEffort[x_][y_]) {
                        minEffort[x_][y_] = maxEffort;
                        pq.push({maxEffort, {x_, y_}});
                    }
                }
            }
        }

        return 0; // unreachable in valid input
    }
};
