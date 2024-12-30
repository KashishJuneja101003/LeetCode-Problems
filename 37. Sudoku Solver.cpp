class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char digit){
        // Horizontally
        for(int j=0; j<9; j++){
            if(board[row][j] == digit) return false;
        }

        // Vertically
        for(int i=0; i<9; i++){
            if(board[i][col] == digit) return false;
        }

        // Grid
        int i = (row/3)*3, j = (col/3)*3;

        for(int a = i; a<=i+2; a++){
            for(int b=j; b<=j+2; b++){
                if(board[a][b] == digit) return false;
            }
        }
        return true;
    }

    bool solver(vector<vector<char>>& board, int row, int col){
        if(row == 9) return true;

        if(board[row][col] != '.'){
            if(col == 9){
                row++; col = 0;
            } else{
                col++;
            }

            return solver(board, row, col);
        }

        // Place correct digit
        for(char i='1'; i<='9'; i++){
            if(isSafe(board, row, col, i)){
                board[row][col] = i;

                if(solver(board, row, col+1)) return true;

                // Backtracking
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solver(board, 0, 0);
    }
};
