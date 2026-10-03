class Solution {
public:
bool solve(vector<vector<char>>& board, string word, int i,int j  , int ind ){
    int m = board.size();
    int n = board[0].size();
    if(word.size() > (m*n)){
        return false;
    }
    if(ind == word.size()){
        return true;
    }
    if(i < 0 || j < 0 || i >= m || j >= n){
    return false;
    }

    if(board[i][j] != word[ind])
            return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = solve(board, word, i+1, j, ind+1) ||
                     solve(board, word, i-1, j, ind+1) ||
                     solve(board, word, i, j+1, ind+1) ||
                     solve(board, word, i, j-1, ind+1);

    board[i][j] = temp;
    return found;

}

    bool exist(vector<vector<char>>& board, string word) { 
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == word[0]) {
                    if(solve(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};