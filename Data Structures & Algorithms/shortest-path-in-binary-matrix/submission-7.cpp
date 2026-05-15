class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int gS = grid.size();

        if(grid[0][0] == 1 || grid[gS-1][gS-1] == 1){
            return -1;
        }

        vector<pair<int,int>> allDirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        vector<vector<int>> visited(gS, vector<int>(gS,-1)); //-1 means not visited
        int length = 1;
        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()){
            int initialQSize = q.size();
            for(int i=0; i<initialQSize; i++){
                auto coords = q.front();
                q.pop();
                int r = coords.first;
                int c = coords.second;
                if(r == gS-1 && c == gS-1){
                    return length;
                }
                for(auto [dr,dc] : allDirs){
                    int nr= r+dr;
                    int nc= c+dc;
                    if(nr >= gS || nc >= gS || nr<0 || nc<0 || grid[nr][nc]==1 || visited[nr][nc] != -1){
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