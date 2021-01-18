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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     
        traverse(0, root);
        
        vector<vector<int>> ans;
        int counter = 0;
        for (auto i = store.begin(); i != store.end(); ++i) {
            if (counter % 2 == 1)
                reverse(i->second.begin(), i->second.end());
            ans.push_back(i->second);
            counter++;
        }
        
        return ans;
    }
    
        
    void traverse(int level, TreeNode *root) {
        
        if (root == NULL)
            return;
        
        if (store.find(level) == store.end()) {
            vector<int> temp;
            store[level] = temp;
        }
            
        store[level].push_back(root->val);
        
        traverse(level + 1, root->left);
        traverse(level + 1, root->right);
    }
};

// Fast I/O; 4 ms
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);