class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> res = board;

        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int live = 0;

                for(int d = 0; d < 8; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];

                    if(x >= 0 && x < m && y >= 0 && y < n) {
                        if(board[x][y] == 1) {
                            live++;
                        }
                    }
                }

                if(board[i][j] == 1) {
                    if(live < 2 || live > 3)
                        res[i][j] = 0;
                    else
                        res[i][j] = 1;
                }
                else {
                    if(live == 3)
                        res[i][j] = 1;
                    else
                        res[i][j] = 0;
                }
            }
        }

        board = res;
    }
};