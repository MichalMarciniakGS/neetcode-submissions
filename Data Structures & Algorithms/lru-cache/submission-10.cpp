class LRUCache {
    unordered_map<int,int> cache;
    int cap;
    list<int> order;

public:
    LRUCache(int capacity) {
        cache.reserve(capacity);
        cap = capacity;
    }
    
    int get(int key) {
        
        if(cache.count(key)){
            auto it = find(order.begin(),order.end(),key);
            order.erase(it);
            order.push_back(key);
            return cache[key];
        }
        return -1;

    }
    
    void put(int key, int value) {

        if(cache.count(key)){
            cache[key] = value;
            auto it = find(order.begin(),order.end(),key);
            order.erase(it);
            order.push_back(key);
        }
        else if(cache.size() == cap){
            cache.erase(order.front());
            order.pop_front();
            cache[key] = value;
            order.push_back(key);
        }else{
            order.push_back(key);
            cache[key] = value;
        }
        
        
    }
};
