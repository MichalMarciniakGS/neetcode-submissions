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
        
        vector<vector<int>> result = {};
        queue<TreeNode*> que = {};

        if(root){
            que.push(root);
        }

        while(!que.empty()){
            vector<int> currentLevel = {};
            int length = que.size();
            for(int i=0; i<length; i++){
                auto currNode = que.front();
                que.pop();
                currentLevel.push_back(currNode->val);
                if(currNode->left){
                    que.push(currNode->left);
                }
                if(currNode->right){
                    que.push(currNode->right);
                }
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};
