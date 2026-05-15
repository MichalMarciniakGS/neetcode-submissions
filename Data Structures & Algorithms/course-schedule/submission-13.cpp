class Solution {

    unordered_map<int,vector<int>> adj;
    unordered_set<int> visited;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for(int i=0; i<numCourses; i++){
            adj[i] = {};
        }

        for(auto prereq : prerequisites){
            adj[prereq[0]].push_back(prereq[1]);
        }

        for(int i=0; i<numCourses; i++){
            if(!dfs(i)){
                return false;
            }
        }

        return true;
        
    }

    bool dfs(int i){

        if(adj[i].empty()){
            return true;
        }

        if(visited.count(i)){
            return false;
        }

        visited.insert(i);
        for(auto prereq : adj[i]){
            if(!dfs(prereq)){
                return false;
            }
        }

        visited.erase(i);
        adj[i].clear();

        return true;


    }
};
