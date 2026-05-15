class TreeNode{
    public:
    int key;
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key, int val){
        this->key = key;
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class TreeMap {

private:
    TreeNode* root;

    void inorderTraversal(TreeNode* root, std::vector<int>& result){

        if (!root){
            return;
        }

        inorderTraversal(root->left, result);
        result.push_back(root->key);
        inorderTraversal(root->right, result);
    }

    TreeNode* findMin(TreeNode* node){
        while(node && node->left){
            node = node->left;
        }
        return node;
    }

    TreeNode* removeHelper(TreeNode* curr, int key){
        if(!curr){
            return nullptr;
        }

        if(key>curr->key){
            curr->right = removeHelper(curr->right, key);
        }
        else if(key < curr->key){
            curr->left = removeHelper(curr->left, key);
        }
        else{
            if(!curr->left){
                return curr = curr->right;
            }
            else if(!curr->right){
                return curr = curr->left;
            }
            else{
                // Swap the current node with the inorder successor (smallest key from right subtree)
                TreeNode* minNode = findMin(curr->right);
                curr->key = minNode->key;
                curr->val = minNode->val;
                curr->right = removeHelper(curr->right, minNode->key);
            }
        }
        return curr;
    }

public:
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        TreeNode* newNode = new TreeNode(key,val);

        if(!root){
            root = newNode;
            return;
        }

        TreeNode* curr = root;
        while(true){
            if(key < curr->key){
                if(!curr->left){
                    curr->left = newNode;
                    return;
                }
                curr = curr->left;
            }
            else if(key > curr->key){
                if(!curr->right){
                    curr->right = newNode;
                    return;
                }
                curr = curr->right;
            }
            else{
                curr->val = newNode->val;
                return;
            }
        }

    }

    int get(int key) {

        TreeNode* curr = root;

        while(curr){
            if(key < curr->key){
                curr = curr->left;
            }
            else if(key > curr->key){
                curr = curr->right;
            }
            else{
                return curr->val;
            }
        }

        return -1;

    }

    int getMin() {

        if(!root){
            return -1;
        }

        TreeNode* curr = root;
        while(curr && curr->left){
            curr = curr->left;
        }
        return curr->val;

    }

    int getMax() {

        if(!root){
            return -1;
        }

        TreeNode* curr = root;
        while(curr && curr->right){
            curr = curr->right;
        }
        return curr->val;

    }

    void remove(int key) {

        root = removeHelper(root,key);
        //Remove the node with key, also return new root of the subtree

    
    }

    std::vector<int> getInorderKeys() {

        std::vector<int> result = {};

        inorderTraversal(root, result);

        return result;

    }
};
