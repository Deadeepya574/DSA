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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int& post, int l, int r) {

        if (l > r) return NULL;

        int val = postorder[post--];

        TreeNode* root = new TreeNode(val);

        int mid = l;
        while (inorder[mid] != val)
            mid++;
  
        root->right = build(inorder, postorder, post, mid + 1, r);
        root->left = build(inorder, postorder, post, l, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post = postorder.size() - 1;

        return build(inorder, postorder, post,
                     0, inorder.size() - 1);
    }
};