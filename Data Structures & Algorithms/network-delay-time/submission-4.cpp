class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        unordered_map<int, vector<pair<int,int>>> edges;

        for(const auto& time : times){
            int src = time[0], trg = time[1], weight = time[2];
            edges[src].push_back({trg,weight});
        }

        int resTime = 0;
        unordered_set<int> visited;

        minHeap.push({0,k});

        while(!minHeap.empty()){
            auto curr = minHeap.top();
            int currTime = curr.first;
            int currNode = curr.second;
            minHeap.pop();

            if(visited.count(currNode)){
                continue;
            }

            visited.insert(currNode);

            resTime = max(resTime, currTime);

            for(const auto& [nextNode,nextTime] : edges[currNode]){
                if(visited.count(nextNode)){
                    continue;
                }
                minHeap.push({currTime+nextTime,nextNode});

            }
        }
        return visited.size() == n ? resTime : -1;
    }
    
};
