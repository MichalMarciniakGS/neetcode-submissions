class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        
        // Find paths from root to both nodes
        findPath(root, p, pathP);
        findPath(root, q, pathQ);
        
        // Find last common node in paths
        TreeNode* lca = nullptr;
        int minLen = min(pathP.size(), pathQ.size());
        
        for (int i = 0; i < minLen; i++) {
            if (pathP[i] == pathQ[i]) {
                lca = pathP[i];
            } else {
                break;
            }
        }
        
        return lca;
    }
    
private:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;
        
        path.push_back(root);
        
        if (root == target) return true;
        
        // Try left and right subtrees
        if (findPath(root->left, target, path) || 
            findPath(root->right, target, path)) {
            return true;
        }
        
        // Backtrack if target not found in this path
        path.pop_back();
        return false;
    }
};

// Time: O(n), Space: O(h) where h is height
// Pro: Easy to understand conceptually
// Con: Requires extra space for paths, multiple tree traversals