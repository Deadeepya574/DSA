/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum,
               vector<vector<int>>& res,
               vector<int>& curr, int sum) {

        if (!root) return;

        curr.push_back(root->val);
        sum += root->val;

        if (!root->left && !root->right && sum == targetSum) {
            res.push_back(curr);
        }

        solve(root->left, targetSum, res, curr, sum);
        solve(root->right, targetSum, res, curr, sum);

        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> curr;

        solve(root, targetSum, res, curr, 0);

        return res;
    }
};