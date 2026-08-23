class Solution {
public:
 bool issorted(vector<int>& nums){
    vector<int> num;
    num = nums;
    
    sort(num.begin(),num.end());
    for(int i =0 ; i<nums.size();i++){
        if(nums[i] == num[0]){
            int count = 0;
            for(int j = i;j<i + nums.size();j++){
                if(nums[j % nums.size()] == num[j - i]){
                    count++;
                    continue;
                }
                else{
                    break;
                }
            }
            if(count == nums.size()){
                return true;
            }
        }
    }
    return false;
 }
    bool check(vector<int>& nums) {
             return issorted(nums);
    }
    
};