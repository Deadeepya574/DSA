class Solution {
public: 
    bool canJump(vector<int>& nums) { 
        int far = 0;
        for(int i =0;i<nums.size();i++){
            if(i> far){
                return false;
            }
            far = max(i+nums[i],far);
            if(far >= nums.size()-1){
                return true;
            } 
        }
        return true;
    }
};