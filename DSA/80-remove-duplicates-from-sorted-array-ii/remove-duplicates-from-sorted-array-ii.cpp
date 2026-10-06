class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int count = 0;

        for(int right = 0; right < nums.size(); right++) {

            if(right == 0 || nums[right] == nums[right - 1]) {
                count++;
            }
            else {
                count = 1;
            }

            if(count <= 2) {
                nums[left] = nums[right];
                left++;
            }
        }

        return left;
    }
};