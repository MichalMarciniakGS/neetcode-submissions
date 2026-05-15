class Graph {
private:
    unordered_map<int,unordered_set<int>> adj_list;

    bool dfs(int src, int dst, unordered_set<int>& visited){
        if(src == dst){
            return true;
        }
        // if(visited.count(src)){
        //     return false;
        // }
        visited.insert(src);
        for(auto neigh : adj_list[src]){
            if(visited.count(neigh) == 0){
                if(dfs(neigh, dst, visited)){
                    return true;
                }
            }
        }
        return false;
    }

public:
    Graph() {}

    void addEdge(int src, int dst) {
        adj_list[src].insert(dst);
    }

    bool removeEdge(int src, int dst) {
        if(adj_list.count(src) == 0 || adj_list[src].find(dst) == adj_list[src].end()){
            return false;
        }
        adj_list[src].erase(dst);
        return true;
    }

    bool hasPath(int src, int dst) {
        // unordered_map<int,int> visited(adj_list.size(),0); To nie zadziala xD
        unordered_set<int> visited;
        return dfs(src,dst,visited);
    }
};
