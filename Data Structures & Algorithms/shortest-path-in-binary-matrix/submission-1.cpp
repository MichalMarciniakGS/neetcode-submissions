class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int gridSize = grid.size();
        vector<vector<int>> visited(gridSize, vector<int>(gridSize, 0)); //0 - not visited
        vector<pair<int,int>> allDirs = {{1,0},{0,1},{1,1},{1,-1},{-1,-1},{-1,0},{0,-1},{-1,1}};
        queue<pair<int,int>> q;
        int length = 1;

        if(grid[0][0] == 1 || grid[gridSize-1][gridSize-1] == 1){
            return -1;
        }

        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()){
            int initialQSize = q.size();
            for(int i=0; i<initialQSize; i++){
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();

                if(cr == gridSize-1 && cc == gridSize-1){
                    return length;
                }

                for(auto [dr,dc] : allDirs){
                    int nr = cr+dr;
                    int nc = cc+dc;
                    if(nr >= gridSize || nc >= gridSize || nr < 0 || nc < 0
                    || grid[nr][nc] == 1 || visited[nr][nc] == 1){
                        continue;
                    }

                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
            length++;
        }
        return -1;

        
    }
};