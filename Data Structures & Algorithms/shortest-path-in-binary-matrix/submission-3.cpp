class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int gridSize = grid.size();
        int length = 1;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(gridSize, vector<int>(gridSize, 0)); // 0 - not visited
        vector<pair<int,int>> allDirs =
        {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};

        if(grid[0][0] == 1 || grid[gridSize-1][gridSize-1] == 1){
            return -1;
        }

        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()){
            int initialSize = q.size();
            
            for(int i=0; i<initialSize; i++){
                pair<int,int> coords= q.front();
                q.pop();
                int cr = coords.first;
                int cc = coords.second;

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
                    
                    q.push({nr,nc});
                    visited[nr][nc] = 1;
                }

            }
            length++;

        }
        return -1;


        
    }
};