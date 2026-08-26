
class NumArray {
    private:
    vector<int> r;
public:

    NumArray(vector<int>& nums) {
         if (nums.empty()) return;
        
        r.resize(nums.size()); // Allocate memory to prevent segmentation faults
        r[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            r[i] = r[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left > 0) {
            return r[right] - r[left-1];
        }
        return r[right];
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */