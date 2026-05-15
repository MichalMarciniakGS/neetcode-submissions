class LRUCache {

    unordered_map<int,pair<int, list<int>::iterator>> mapp;
    list<int> order;
    int max;

public:
    LRUCache(int capacity) {
        max = capacity;
    }
    
    int get(int key) {

        if(mapp.count(key) == 1){
            order.erase(mapp[key].second);
            order.push_back(key);
            auto it = order.end();
            --it;
            mapp[key].second = it;
            return mapp[key].first;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        
        if(mapp.count(key) == 1){
            order.erase(mapp[key].second);
        }else if(mapp.size() >= max){
            int X = order.front();
            order.pop_front();
            mapp.erase(X);
        }
        order.push_back(key);
        auto it = order.end();
        --it;
        mapp[key] = {value, it};

    }
};
