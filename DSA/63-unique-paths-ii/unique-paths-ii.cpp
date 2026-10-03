class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j,vector<vector<int>>& dp) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(i >= m || j >= n)
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(obstacleGrid[i][j] == 1){
            return 0;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = solve(obstacleGrid, i, j+1,dp);
        int down = solve(obstacleGrid, i+1, j,dp);

        return dp[i][j] = right + down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 ){
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, 0, 0,dp);
    }
};