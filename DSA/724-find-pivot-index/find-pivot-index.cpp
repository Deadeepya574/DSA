class Solution {
public:

    int pivotIndex(vector<int>& nums) {
         int totalSum = 0;
        int leftSum = 0;
        
        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }
        
        // Check each index as a potential pivot
        for (int i = 0; i < nums.size(); i++) {
            // Right sum is totalSum - leftSum - current element
            if (leftSum == (totalSum - leftSum - nums[i])) {
                return i; 
            }
            leftSum += nums[i];
        }
        
        return -1;
    }
};