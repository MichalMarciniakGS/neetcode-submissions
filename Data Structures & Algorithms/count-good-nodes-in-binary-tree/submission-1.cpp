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
    int goodNodes(TreeNode* root) {

        int res = 1;
        dfs(root,res,root->val);
        return res;
        
    }

    void dfs(TreeNode* node, int& res, int maxVal){

        if(!node){
            return;
        }

        maxVal = max(maxVal, node->val);

        if(node->left){
            if(node->left->val >= maxVal){
                res++;
            }
            dfs(node->left, res, maxVal);
        }

        if(node->right){
            if(node->right->val >= maxVal){
                res++;
            }
            dfs(node->right, res, maxVal);
        }

    }
};
