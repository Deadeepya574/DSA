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
    int inorder(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (root->left == NULL && root->right == NULL) {
            return 1;
        }

        int left = inorder(root->left);
        int right = inorder(root->right);

        if (root->left == NULL) {
            return right + 1;
        }

        if (root->right == NULL) {
            return left + 1;
        }

        return min(left, right) + 1;
    }

    int minDepth(TreeNode* root) {
        return inorder(root);
    }
};