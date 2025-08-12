// DFS TC: O(m*n*(4^l)) SC: O(m*n)
class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int x, int y, int m, int n){
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool DFS(vector<vector<char>>& board, string word, int x, int y, int i, vector<vector<bool>>& visited){
        if(i == word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        visited[x][y] = true;

        for(vector<int>& dir:directions){
            int x_ = x + dir[0];
            int y_ = y + dir[1];

            if(isSafe(x_, y_, m, n) && !visited[x_][y_] && board[x_][y_] == word[i]){
                if(DFS(board, word, x_, y_, i+1, visited)){
                    return true;
                }
            }
        }

        visited[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && board[i][j] == word[0]){
                    if(DFS(board, word, i, j, 1, visited)){
                        return true;
                    }
                }
            }
        }

        return false;
   }
};

// DFS - Space Optimized TC: O(m*n*(4^l)) SC: O(1)
class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int x, int y, int m, int n){
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool DFS(vector<vector<char>>& board, string word, int x, int y, int i){
        if(i == word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        char temp = board[x][y];
        board[x][y] = '.';

        for(vector<int>& dir:directions){
            int x_ = x + dir[0];
            int y_ = y + dir[1];

            if(isSafe(x_, y_, m, n) && board[x_][y_] != '.' && board[x_][y_] == word[i]){
                if(DFS(board, word, x_, y_, i+1)){
                    return true;
                }
            }
        }

        board[x][y] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] != '.' && board[i][j] == word[0]){
                    if(DFS(board, word, i, j, 1)){
                        return true;
                    }
                }
            }
        }

        return false;
   }
};
