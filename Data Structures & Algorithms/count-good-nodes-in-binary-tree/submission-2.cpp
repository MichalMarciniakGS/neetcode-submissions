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

        int res = 0;
        int maxVal = root->val;

        counter(root, res, maxVal);

        return res;
        
    }

    void counter(TreeNode* node, int& res, int maxVal){

        if(node){

             maxVal = max(maxVal, node->val);
             if(node->val >= maxVal){
                res++;
             }

            if(node->left){
                counter(node->left, res, maxVal);
            }

            if(node->right){
                counter(node->right, res, maxVal);
            }
        }

    }
};
