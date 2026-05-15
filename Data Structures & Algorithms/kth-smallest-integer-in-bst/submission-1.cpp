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
    int kthSmallest(TreeNode* root, int k) {
        
        if(!root){
            return 0;
        }

        vector<int> result = {};

        inorder(root,result);

        // sort(result.begin(), result.end());

        return result[k-1];

    }

    void inorder(TreeNode* node, vector<int>& result){

        if(!node){
            return;
        }

        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right,result);
    }
};
