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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result = {};
        queue<TreeNode*> q = {};

        if(root){
            q.push(root);
        }

        while(q.size() > 0){
            int length = q.size();
            vector<int> arr = {};
            for(int i = 0; i<length; i++){
                TreeNode* current = q.front();
                q.pop();
                arr.push_back(current->val);

                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
            length++;
            result.push_back(arr.back());
        }

        return result;

    }
};
