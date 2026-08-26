class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int sum =0;
         int mini = INT_MAX;
         int left =0;
         int right = 0;
         while( right < nums.size()){
             sum += nums[right];
                right++;
             while ( sum >= target){
                mini = min(right-left,mini); 
                sum -= nums[left];
                left++;
            } 
         }
         return (mini == INT_MAX) ? 0 : mini ;

    }
};