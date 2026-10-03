class Solution {
public:
    bool solve(vector<int>& nums, vector<bool>& used,
               int start, int currSum, int k, int target) {

        if(k == 1)
            return true;

        if(currSum == target)
            return solve(nums, used, 0, 0, k-1, target);

        for(int i = start; i < nums.size(); i++) {

            if(used[i])
                continue;

            if(currSum + nums[i] > target)
                continue;

            used[i] = true;

            if(solve(nums, used, i+1, currSum + nums[i], k, target))
                return true;

            used[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = 0;
        for(int x : nums)
            sum += x;

        if(sum % k != 0)
            return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if(nums[0] > target)
            return false;

        vector<bool> used(nums.size(), false);

        return solve(nums, used, 0, 0, k, target);
    }
};