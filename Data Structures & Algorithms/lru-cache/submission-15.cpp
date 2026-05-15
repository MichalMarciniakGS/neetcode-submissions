class LRUCache {
    unordered_map<int,pair<int,list<int>::iterator>> cache;
    int cap;
    list<int> order;

public:
    LRUCache(int capacity) {
        cache.reserve(capacity);
        cap = capacity;
    }
    
    int get(int key) {
        
        if(cache.count(key)){
            // auto it = find(order.begin(),order.end(),key);
            order.erase(cache[key].second);
            order.push_back(key);
            cache[key].second = --order.end();
            return cache[key].first;
        }
        return -1;

    }
    
    void put(int key, int value) {

        if(cache.count(key)){
            // auto it = find(order.begin(),order.end(),key);
            order.erase(cache[key].second);
            order.push_back(key);
            cache[key] = {value,--order.end()};
        }
        else if(cache.size() == cap){
            cache.erase(order.front());
            order.pop_front();
            order.push_back(key);
            cache[key] = {value,--order.end()};
        }else{
            order.push_back(key);
            cache[key] = {value,--order.end()};
        }
        
        
    }
};
