class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        // Prefix sum 0 before the array starts
        mp[0] = -1;

        int sum = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {

            // Convert:
            // 0 -> -1
            // 1 -> +1

            if(nums[i] == 0)
                sum--;
            else
                sum++;

            // Same prefix sum seen before
            if(mp.find(sum) != mp.end()) {

                ans = max(ans, i - mp[sum]);

            }
            else {

                // Store FIRST occurrence only
                mp[sum] = i;
            }
        }

        return ans;
    }
};