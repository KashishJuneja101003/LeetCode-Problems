// Both BFS and DFS has TC: O(n) SC: O(n)
// BFS (Safe code for large inputs)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();

        int start = image[sr][sc];
        if(start == color) return image;
        
        vector<vector<int>> result = image;

        // q stores the index which is filled with color
        queue<pair<int, int>> q;
        q.push({sr, sc});


        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            result[r][c] = color;

            // Check Left
            if(c-1 >= 0 && result[r][c-1] != color && image[r][c-1] == start) q.push({r, c-1});
            
            // Check Right
            if(c+1 < cols && result[r][c+1] != color && image[r][c+1] == start) q.push({r, c+1});
            
            // Check Up
            if(r-1 >= 0 && result[r-1][c] != color && image[r-1][c] == start) q.push({r-1, c});

            // Check Down
            if(r+1 < rows && result[r+1][c] != color && image[r+1][c] == start) q.push({r+1, c});
        }

        return result;
    }
};

// DFS (Better code)
class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int start){
        int rows = image.size();
        int cols = image[0].size();

        // Boundary Check
        if(r < 0 || r >= rows || c < 0 || c >= cols) return;

        // If current pixel is not equal to starting pixel, return.
        if(image[r][c] != start) return;

        image[r][c] = color;

        // Call DFS for all 4 directions
        dfs(image, r-1, c, color, start);
        dfs(image, r+1, c, color, start);
        dfs(image, r, c-1, color, start);
        dfs(image, r, c+1, color, start);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        if(start == color) return image;

        dfs(image, sr, sc, color, start);

        return image;
    }
};
