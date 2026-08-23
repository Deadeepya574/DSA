class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
          if(nums.size() == 1){
            return 1;
          }
          int left = 0;
          int right = 1;
          while(left<=right && right<nums.size() && left < nums.size()){
            if(nums[left] == nums[right]){ 
                right++;
            }
            else if(nums[left] < nums[right]){
                left++;
                nums[left] = nums[right];
                right++;
            }
          }
          return left+1;
    }
};