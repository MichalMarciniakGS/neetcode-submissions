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

        while(!q.empty()){
            int length = q.size();
            vector<int> singleLevelResult = {};

            for(int i = 0; i<length; i++){
                TreeNode* currentNode = q.front();
                q.pop();
                singleLevelResult.push_back(currentNode->val);

                if(currentNode->left){
                    q.push(currentNode->left);
                }

                if(currentNode->right){
                    q.push(currentNode->right);
                }

            }
            result.push_back(singleLevelResult.back());
        }
        return result;

    }
};
