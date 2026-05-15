class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int max;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;

        prev->next = nxt;
        nxt->prev = prev;

    }

    void insert(Node* node){

        Node* rPrev = right->prev;
        rPrev->next = node;
        node->prev = rPrev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        max = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.count(key) == 1){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {

        if(cache.count(key) == 1){
            Node* newNode = new Node(key,value);
            remove(cache[key]);
            cache[key] = newNode;
            insert(newNode);
        }else if(cache.size() >= max){
            Node* afterLeftNode = left->next;
            remove(afterLeftNode);
            cache.erase(afterLeftNode->key);
            delete afterLeftNode;

            Node* newNode = new Node(key,value);
            cache[key] = newNode;
            insert(newNode);
        }else{
            
            Node* newNode = new Node(key,value);
            cache[key] = newNode;
            insert(newNode);
        }

        
    }
};
