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
        
        queue<TreeNode*> q = {};
        vector<int> result = {};

        if(root){
            q.push(root);
        }

        stack<int> allVals = {};



        while(!q.empty()){
            int length = q.size();
            vector<int> arr = {};

            for(int i=0; i<length; i++){
                TreeNode* currNode = q.front();
                q.pop();
                arr.push_back(currNode->val);

                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }

            }
            result.push_back(arr.back());

        }
        return result;
    }
};
