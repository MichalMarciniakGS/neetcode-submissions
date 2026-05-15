class LRUCache {

    unordered_map<int,pair<int, list<int>::iterator>> cache;
    list<int> recentlyUsed;
    int cap;

public:
    LRUCache(int capacity) {

        cache.reserve(capacity);
        cap = capacity;
        
    }
    
    int get(int key) {

        if(cache.count(key)){
            recentlyUsed.erase(cache[key].second);   // Remove key from the list //
            recentlyUsed.push_back(key);
            cache[key].second = --recentlyUsed.end();
            return cache[key].first;
        }
        return -1;
        
    }
    
    void put(int key, int value) {

        if(cache.count(key)){
            recentlyUsed.erase(cache[key].second); // Remove key from the list //
            recentlyUsed.push_back(key);
            cache[key] = {value, --recentlyUsed.end()};
        }
        else if(cache.size() == cap){
            //We need to get leastUsedKey
            int leastUsedKey = recentlyUsed.front();
            //Delete it from the list
            recentlyUsed.erase(recentlyUsed.begin());
            //Delete it from the cache
            cache.erase(leastUsedKey);

            recentlyUsed.push_back(key);
            cache[key] = {value, --recentlyUsed.end()};
        }
        else{
            recentlyUsed.push_back(key);
            cache[key] = {value, --recentlyUsed.end()};
        }
        
    }
};
