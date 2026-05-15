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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> q = {};
        vector<vector<int>> allVec = {};

        if(!root){
            return {};
        }

        if(root){
            q.push(root);
        }

        int level = 0;
        while(q.size()>0){
            int length = q.size();
            vector<int> arr = {};
            for(int i = 0; i < length; i++){
                TreeNode* curr = q.front();
                q.pop();
                arr.push_back(curr->val);

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            allVec.push_back(arr);
            level++;
        }

        return allVec;
        

    }
};
