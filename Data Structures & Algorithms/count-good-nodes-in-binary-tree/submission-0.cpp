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
        int curVal = root->val;

        helper(root, res, curVal);

        return res;
        
    }

    void helper(TreeNode* curNode, int& res, int curVal){
        
        curVal = max(curVal, curNode->val);

        if(curNode->left){
            if(curNode->left->val >= curVal){
                res++;
            }
            helper(curNode->left, res, curVal);
        }

        if(curNode->right){
            if(curNode->right->val >= curVal){
                res++;
            }
            helper(curNode->right, res, curVal);
        }
    }
};
