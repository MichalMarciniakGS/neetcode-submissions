class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        unordered_set<int> visited;

        unordered_map<int, vector<pair<int,int>>> adjList;

        int maxTime = -10;

        for(auto currVec : times){

            int source = currVec[0];
            int target = currVec[1];
            int time = currVec[2];

            adjList[source].push_back({target,time});

        }

        minHeap.push({0,k});
        // visited.insert(k);

        while(!minHeap.empty()){

            auto topPair = minHeap.top();
            minHeap.pop();

            int currTime = topPair.first;
            int currNode = topPair.second;

            if(visited.count(currNode)){
                continue;
            }

            visited.insert(currNode);
            maxTime = max(maxTime,currTime);

            for(auto [nextNode, nextTime] : adjList[currNode]){

                int sumTime = currTime + nextTime;

                if(visited.count(nextNode)){
                    continue;
                }

                minHeap.push({sumTime,nextNode});

            }

        }

        return (visited.size() == n) ? maxTime : -1;
        
    }
};
