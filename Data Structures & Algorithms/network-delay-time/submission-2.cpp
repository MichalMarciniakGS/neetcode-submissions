class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        unordered_map<int, vector<pair<int,int>>> edges;
        for(auto time : times){
            int s=time[0], target=time[1], weight=time[2];
            edges[s].push_back({target,weight});
        }

        minHeap.push({0,k});
        unordered_set<int> visited;

        int finalTime=0;

        while(!minHeap.empty()){
            auto curr = minHeap.top();
            int currTime = curr.first;
            int currNode = curr.second;

            minHeap.pop();

            if(visited.count(currNode)){
                continue;
            }

            visited.insert(currNode);
            finalTime = max(finalTime, currTime);

            for(auto next : edges[currNode]){
                int nextNode = next.first;
                int nextTime = next.second;
                if(!visited.count(nextNode)){
                    minHeap.push({currTime+nextTime, nextNode});
                }
            }
        }
        return visited.size() == n ? finalTime : -1;
        
    }
};
