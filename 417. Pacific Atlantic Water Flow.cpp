// TC: O(m*n) SC: O(m*n)
class Solution {
public:
    int m;
    int n;

    vector<vector<int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    bool isSafe(int x, int y) { return x >= 0 && y >= 0 && x < m && y < n; }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;

        vector<vector<bool>> visited1(m, vector<bool>(n, false));
        vector<vector<bool>> visited2(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            q1.push({i, 0});
            visited1[i][0] = true;
        }
        for (int j = 0; j < n; j++) {
            q1.push({0, j});
            visited1[0][j] = true;
        }
        for (int i = 0; i < m; i++) {
            q2.push({i, n - 1});
            visited2[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            q2.push({m - 1, j});
            visited2[m - 1][j] = true;
        }

        while (!q1.empty()) {
            int x = q1.front().first;
            int y = q1.front().second;
            q1.pop();

            for (auto& dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_) && !visited1[x_][y_] &&
                    heights[x_][y_] >= heights[x][y]) {
                    visited1[x_][y_] = true;
                    q1.push({x_, y_});
                }
            }
        }

        while (!q2.empty()) {
            int x = q2.front().first;
            int y = q2.front().second;
            q2.pop();

            for (auto& dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_) && !visited2[x_][y_] &&
                    heights[x_][y_] >= heights[x][y]) {
                    visited2[x_][y_] = true;
                    q2.push({x_, y_});
                }
            }
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited1[i][j] && visited2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
