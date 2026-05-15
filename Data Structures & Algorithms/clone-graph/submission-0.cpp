/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr){
            return nullptr;
        }

        if(node->neighbors.empty()){
            return new Node(node->val);
        }
        
        unordered_map<Node*, Node*> oldToNew;

        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldToNew){
        if(oldToNew.count(node)){
            return oldToNew[node];
        }

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for(auto singleNeighbor : node->neighbors){
            copy->neighbors.push_back(dfs(singleNeighbor, oldToNew));
        }
        return copy;
    }
};
