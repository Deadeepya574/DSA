class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr,
               vector<int>& vis, vector<vector<int>>& ans) {

        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(vis[i]) continue;

            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1])
                continue;

            vis[i] = 1;
            curr.push_back(nums[i]);

            solve(nums, curr, vis, ans);

            curr.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> vis(nums.size(), 0);

        solve(nums, curr, vis, ans);

        return ans;
    }
};