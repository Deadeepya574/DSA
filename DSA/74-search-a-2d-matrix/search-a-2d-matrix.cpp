class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i =0;
        int j = matrix.size()-1;
        while(i <= j ){
            int mid = (i+j) / 2;
            if(matrix[mid][0] == target){
                return true;
            }
            else if ( matrix[mid][0] < target && mid + 1 < matrix.size() && matrix[mid+1][0] > target){
                int start =0;
                int end = matrix[0].size()-1;
                    while(start <= end  ){
                        
                 int p = (start + end) / 2 ;
                 
                    if(matrix[mid][p] == target){
                        return true;
                    }
                    else if( matrix[mid][p] < target){
                        start = p + 1;
                    }
                    else {
                        end = p -1;
                    }

                    }

                     return false;
                }
            
            else if(matrix[mid][0] < target){
                i = mid + 1;
            }
            else {
                j = mid-1;
            }

    }
    int row = matrix.size() - 1;
        int start = 0;
        int end = matrix[0].size() - 1;

        while(start <= end) {
            int p = (start + end) / 2;

            if(matrix[row][p] == target) return true;
            else if(matrix[row][p] < target) start = p + 1;
            else end = p - 1;
        }
        
    return false;
    }
};