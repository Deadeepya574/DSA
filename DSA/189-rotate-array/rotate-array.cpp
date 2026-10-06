class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> num = nums;
        for(int i = k ;i < k + nums.size();i++){
            nums[i % (nums.size())] = num[i - k];
        }        
    }
};