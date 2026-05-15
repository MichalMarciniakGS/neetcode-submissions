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

    bool dfs(int c){

        if(adj[c].empty()){
            return true;
        }

        if(visited.count(c)){
            return false;
        }

        visited.insert(c);

        for(int prereq : adj[c]){
            if(!dfs(prereq)){
                return false;
            }
        }

        visited.erase(c);
        adj[c].clear();

        return true;

    }
};
