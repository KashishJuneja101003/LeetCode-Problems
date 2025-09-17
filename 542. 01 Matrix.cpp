class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int x, int y) { return x >= 0 && y >= 0 && x < m && y < n; }

    int m, n;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;
        int ones = 0;
        int dist = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = true;
                    q.push({i, j});
                } else
                    ones++;
            }
        }

        while (!q.empty() && ones != 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (auto& dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (isSafe(x_, y_) && !visited[x_][y_] &&
                        mat[x_][y_] != 0) {
                        visited[x_][y_] = true;
                        mat[x_][y_] = dist;
                        q.push({x_, y_});
                        ones--;
                    }
                }
            }

            dist++;
        }

        return mat;
    }
};
