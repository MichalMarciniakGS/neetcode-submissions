class Solution {

    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //[0,1], [1,0]

        //Is empty initialization required? - YEs it is, without it there would be no empty
        // courses in map

        for(int j=0; j<numCourses; j++){
            preMap[j] = {};
        }

        for(auto preReq : prerequisites){
            // preMap[preReq[0]] = preMap[preReq[0]].push_back(preReq[1]); cant do it like this
            preMap[preReq[0]].push_back(preReq[1]);
        }

        for(int i=0; i<numCourses; i++){
            if(!dfs(i)){
                return false;
            }
        }
        return true;

    }

    bool dfs(int c){

        if(preMap[c].empty()){
            return true;
        }

        if(visited.count(c)){
            return false;
        }

        visited.insert(c);
        for(auto neighbour : preMap[c]){
            if(!dfs(neighbour)){
                return false;
            }
        }
        visited.erase(c);
        preMap[c].clear();

        return true;

    }
};
