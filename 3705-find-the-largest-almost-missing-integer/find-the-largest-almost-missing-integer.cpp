class Solution {
public:
int maxi(vector<int>& nums){
    int max = nums[0];
    for(int i = 1;i<nums.size();i++){
if(nums[i] > max){
    max = nums[i];
}
    }
    return max;
}
int maxandonce(vector<int>& nums){
    unordered_map<int,int> count;
    for(int num : nums){
        count[num]++;
    }
    int largestUnique = -1;
    
    for (const auto& pair : count) {
        if (pair.second == 1) {
            if (pair.first > largestUnique) {
                largestUnique = pair.first;
            }
        }
    }
    
    return largestUnique;
}
int occurence(vector<int>& nums,int p){
int count =0;
for(int i =0;i<nums.size();i++){
    if(nums[i] == p){
 count++;
    }
}
return count;
}
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int max = 0;
        if(k == 1){
            return maxandonce(nums);
        }
        else if(k == n){
            return maxi(nums);
        }
        else{
            int count1 = occurence(nums,nums[0]);
            int count2 = occurence(nums,nums[n-1]);
            if(count1 == 1 && count2 == 1){
                return (nums[0] > nums[n-1]) ? nums[0] : nums[n-1];
            }
            else if(count1 > 1 && count2 ==1 ){
                return nums[n-1];
            }
            else if(count1 == 1 && count2 > 1 ){
                return nums[0];
            }
            else if(count1 > 1 && count2 > 1){
                return -1;
            }
        }
 
return -1;
    }
};