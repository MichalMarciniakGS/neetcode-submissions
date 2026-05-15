class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int,int>>> adj;

        for(vector<int>& time : times){
            int s=time[0], d=time[1], w=time[2];
            adj[s].push_back({d,w});
        }

        unordered_set<int> visited;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0,k});
        int t =0;

        while(!minHeap.empty()){
            pair<int,int> curr = minHeap.top();
            minHeap.pop();
            int w1=curr.first, n1=curr.second;
            if(visited.count(n1)) continue;
            visited.insert(n1);
            t = w1;
            if(adj.count(n1)){
            for(auto next : adj[n1]){
                int n2=next.first, w2=next.second;
                if(!visited.count(n2)){
                    minHeap.push({w1+w2,n2});
                }
                }
            }
        }
        
        return visited.size() == n ? t : -1;
    }
};
