class Solution {

    vector<vector<int>> visited;

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        visited.assign(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        int cr=0;
        int cc=0;

        return helper(cr, cc, obstacleGrid, visited);
    }

    int helper(int cr, int cc, vector<vector<int>>& obstacleGrid, vector<vector<int>>& visited){

        if(cr >= obstacleGrid.size() || cc >= obstacleGrid[0].size()
        || obstacleGrid[cr][cc] != 0){
            return 0;
        }

        if(visited[cr][cc] != -1){
            return visited[cr][cc];
        }

        if(cr == obstacleGrid.size()-1 && cc == obstacleGrid[0].size()-1){
            return 1;
        }

        visited[cr][cc] = helper(cr+1, cc, obstacleGrid, visited) + helper(cr, cc+1, obstacleGrid, visited);

        return visited[cr][cc];

    }
};