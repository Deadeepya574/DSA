class Solution {
public:
    void solve(vector<int>& candidates, int target, int i,
               vector<int>& curr, vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        if(i == candidates.size() || target < 0) {
            return;
        } 
        curr.push_back(candidates[i]);

        solve(candidates, target - candidates[i], i, curr, ans);

        curr.pop_back(); 
        solve(candidates, target, i + 1, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, 0, curr, ans);

        return ans;
    }
};