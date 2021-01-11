
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	vector<int> ans;
    bool found = false;
    int backtrackCount = 0;

    void process(TreeNode *node, int K, TreeNode *target) {

    	if (node == NULL)
    		return;

    	int side = 1;

    	process(node->left, K, target);

    	if (!found && node == target) {
    		found = true;
    		calculateNodesAndSave(node, K);
    		return;
    	}

    	if (!found) {
    		side = 2;
			process(node->right, K, target);
    	}

    	if (found)
 	    	postProcess(node, side, K);
        
    }

    void calculateNodesAndSave(TreeNode *node, int K) {
    	if (node == NULL || K < 0)
    		return;
    	if (K == 0)
    		ans.push_back(node->val);
    	calculateNodesAndSave(node->left, K-1);
    	calculateNodesAndSave(node->right, K-1);
    }

    void postProcess(TreeNode *node, int side, int K) {
    	//if side is 1 -> left is explored, go right
    	//if side is 2 -> right is explored, go left
    	if (node == NULL || backtrackCount > K)
    		return;

    	backtrackCount++;
        

    	if (K - backtrackCount == 0) 
    		ans.push_back(node->val);
    	else if (side == 1) 
    		calculateNodesAndSave(node->right, K - backtrackCount - 1);
    	else
    		calculateNodesAndSave(node->left, K - backtrackCount - 1);

    }
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    
    	if (root == NULL || target == NULL)
    		return ans;

    	process(root, K, target);

    	return ans;

    }

};