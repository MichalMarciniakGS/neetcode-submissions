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
        int curMax = root->val;

        helper(root,res,curMax);

        return res;
        
    }

    void helper(TreeNode* node, int& res, int curMax){

        if(node == nullptr){
            return;
        }
        
        curMax = max(curMax, node->val); // 2 -> 2

        if(node->left){
            if(curMax <= node->left->val){
                res++; // 1+1=2
            }
            helper(node->left,res,curMax);
        }

        if(node->right){
            if(curMax <= node->right->val){
                res++; // 2+1=3
            }
            helper(node->right,res,curMax);
        }

        return;

    }
};
