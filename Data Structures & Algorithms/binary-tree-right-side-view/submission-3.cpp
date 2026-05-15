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

        if(!root){
            return {};
        }

        vector<int> res;
        queue<TreeNode*> q;

        q.push(root);


        while(!q.empty()){
            int qSize = q.size();
            vector<int> singleLevelRes;
            for(int i=0; i<qSize; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(i == qSize-1){
                    res.push_back(node->val);
                }

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            // res.push_back(singleLevelRes.back());


        }
        return res;

        
    }
};
