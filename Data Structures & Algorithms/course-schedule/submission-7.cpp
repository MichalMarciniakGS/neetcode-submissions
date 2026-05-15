class Solution {
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visitSet= {};
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for(int i=0; i<numCourses; i++){
            preMap[i] = {};
        }

        for(auto preReq : prerequisites){
            preMap[preReq[0]].push_back(preReq[1]);
        }

        for(int c = 0; c<numCourses; c++){
            if(!dfs(c)){
                return false;
            }
        }
        return true;

    }

    bool dfs(int currentCrs){
        if(visitSet.count(currentCrs)){
            return false;
        }
        if(preMap[currentCrs].empty()){
            return true;
        }
        visitSet.insert(currentCrs);
        for(auto singleCrs : preMap[currentCrs]){
            if(!dfs(singleCrs)){
                return false;
            }
        }

        visitSet.erase(currentCrs);
        preMap[currentCrs] = {};
        return true;

    }
};
