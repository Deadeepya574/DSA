class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
         int m = grid.size();
         int n = grid[0].size();
long long  total = 0;
         for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
total += grid[i][j];
            }
         }
long long upper =0;
         for(int i =0 ;i<m;i++){
            for(int j= 0;j<n;j++){
upper += grid[i][j];
            }

            long long lower = total - upper;
            if(upper == lower){
                return true;
            }
         }
long long left = 0;
         for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
left += grid[j][i];
            }
            long long right = total - left;
            if(left == right){
                return true;
            }
         }

         return false;
    }
};