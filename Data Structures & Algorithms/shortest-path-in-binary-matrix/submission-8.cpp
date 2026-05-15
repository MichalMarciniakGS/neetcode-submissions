class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int gS = grid.size();
        vector<vector<int>> visited(gS, vector<int>(gS, -1));
        int length = 1;

        if(grid[0][0] == 1 || grid[gS-1][gS-1] == 1){
            return -1;
        }

        vector<pair<int,int>> allDirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()){

            int currQSize = q.size();

            for(int i=0; i<currQSize; i++){

                auto [cr,cc] = q.front();
                q.pop();

                if(cr == gS-1 && cc == gS-1){
                    return length;
                }

                for(auto [dr,dc] : allDirs){
                    int nr = cr+dr;
                    int nc = cc+dc;

                    if(nr >= gS || nc >= gS || nr < 0 || nc < 0 || visited[nr][nc] != -1
                        || grid[nr][nc] == 1){
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