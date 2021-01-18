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
    map<int, vector<int>> store;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
    
        traverse(0, root);
        
        vector<vector<int>> ans;
        for (auto i = store.begin(); i != store.end(); ++i) 
            ans.push_back(i->second);
        
        return ans;
        
    }
    
    void traverse(int level, TreeNode *root) {
        
        if (root == NULL)
            return;
        
        if (store.find(level) == store.end()) {
            vector<int> temp;
            temp.push_back(root->val);
            store[level] = temp;
        } else        
            store[level].push_back(root->val);
        
        traverse(level + 1, root->left);
        traverse(level + 1, root->right);
    }
};