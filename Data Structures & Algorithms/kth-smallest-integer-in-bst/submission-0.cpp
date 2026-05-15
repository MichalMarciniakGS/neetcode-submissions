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
        
        vector<int> arr(2);
        arr[0] = k;

        dfs(root, arr);

        return arr[1];

    }

    void dfs(TreeNode* node, vector<int>& arr){
        if(!node){
            return;
        }
        dfs(node->left,arr);
        arr[0]--;
        if(arr[0] == 0){
            arr[1] = node->val;
            return;
        }
        dfs(node->right, arr);
    }
};
