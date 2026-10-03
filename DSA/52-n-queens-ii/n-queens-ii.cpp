class Solution {
public:
    int count = 0;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        int i = row - 1, j = col - 1;

        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        i = row - 1;
        j = col + 1;

        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board) {

        if(row == n) {
            count++;
            return;
        }

        for(int col = 0; col < n; col++) {

            if(isSafe(board, row, col, n)) {

                board[row][col] = 'Q';

                solve(row + 1, n, board);

                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(0, n, board);

        return count;
    }
};