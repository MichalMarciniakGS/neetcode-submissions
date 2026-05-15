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

        if(!root){
            return 0;
        }

        // TreeNode* dummy = new TreeNode();
        // TreeNode* node = dummy;
        int curMax = root->val;
        int res = 1;

        helper(root, res, curMax);

        return res;
        
    }

    void helper(TreeNode* node, int& res, int curMax){

        if(node == nullptr){
            return;
        }

        curMax = max(curMax,node->val);

        if(node->left){
            if(node->left->val >= curMax){
                res++;
            }
            helper(node->left, res, curMax);
        }

        if(node->right){
            if(node->right->val >= curMax){
                res++;
            }
            helper(node->right, res, curMax);
        }

        return;

    }
};
