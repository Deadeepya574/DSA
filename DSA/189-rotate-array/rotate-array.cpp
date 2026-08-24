class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> num = nums;
        int i = k;
        while(i <= k + nums.size()){
            nums[i % (nums.size())] = num[(i-k) % nums.size()];
            i++;
        }

         
    }
};