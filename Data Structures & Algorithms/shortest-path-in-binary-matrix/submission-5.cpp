class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int gS = grid.size();
        int res = 1;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(gS, vector<int>(gS,0)); //0 - not visited
        vector<pair<int,int>> allDirs = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

        if(grid[0][0] == 1 || grid[gS-1][gS-1] == 1){
            return -1;
        }

        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()){
            int initialSize = q.size();
            for(int i=0; i<initialSize; i++){
                auto coords = q.front();
                q.pop();
                int cr = coords.first;
                int cc = coords.second;

                if(cr == gS-1 && cc == gS-1){
                    return res;
                }

                //structure binding
                for(auto [dr,dc] : allDirs){
                    int nr = cr+dr;
                    int nc = cc+dc;

                    if(nr >= gS || nc >= gS || nr < 0 || nc < 0 || grid[nr][nc] == 1
                     || visited[nr][nc] == 1){
                        continue;
                     }

                     visited[nr][nc] = 1;
                     q.push({nr,nc});
                }

            }
            res++;

        }
        return -1;



        
    }
};