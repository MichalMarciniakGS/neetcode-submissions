class Solution {

    unordered_map<int,vector<int>> adj;
    vector<int> state; //0-unvisited 1-visiting 2-visited

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        state.assign(numCourses, 0);

        // for(int i=0; i<numCourses; i++){
        //     adj[i].push_back({});
        // }

        for(auto prereq : prerequisites){
            adj[prereq[0]].push_back(prereq[1]);
        }

        for(int i=0; i<numCourses; i++){
            if(state[i] == 0 && hasCycle(i)){
                return false;
            }
        }

        return true;
        
    }

    bool hasCycle(int i){

        if(state[i] == 1) return true;
        if(state[i] == 2) return false;

        state[i] = 1;

        for(int prereq : adj[i]){
            if(hasCycle(prereq)){
                return true;
            }
        }

        state[i] = 2;
        return false;


    }
};
