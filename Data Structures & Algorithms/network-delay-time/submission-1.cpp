class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, vector<pair<int,int>>> edges;

        for(auto time : times){
            int s=time[0], t=time[1], w=time[2];
            edges[s].push_back({t,w});
            //s-source
            //t-target
            //w-weight
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0,k});

        unordered_set<int> visited; //track of nodes we already visited
        int t=0; // result

        while(!minHeap.empty()){

            auto currPair = minHeap.top();
            int w1 = currPair.first; // time to reach node
            int n1 = currPair.second;
            minHeap.pop();
            if(visited.count(n1)){
                continue;
            }
            visited.insert(n1);
            t = max(t,w1);

            for(const auto& next : edges[n1]){
                int n2= next.first;
                int w2 = next.second;

                if(!visited.count(n2)){
                    minHeap.push({w1+w2,n2});
                }

            }
        }
        return visited.size() == n ? t : -1;
    }
};
