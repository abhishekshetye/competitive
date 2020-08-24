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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumLeft(root, true);
    }

    int sumLeft(TreeNode *node, bool isLeft) {
    	if (node == NULL)
    		return 0;
    	if (node->left == NULL && node->right == NULL && isLeft)
    		return node->val;
    	return sumLeft(node->left, true) + sumLeft(node->right, false);
    }
};