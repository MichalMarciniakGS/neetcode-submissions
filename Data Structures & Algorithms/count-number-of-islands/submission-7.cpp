class Solution {

    vector<vector<int>> visited;

public:
    int numIslands(vector<vector<char>>& grid) {

        int rS = grid.size();
        int cS = grid[0].size();

        int islandsNumber = 0;

        visited.assign(rS, vector<int>(cS,0)); // 0- not visited

        for(int r=0; r<rS; r++){
            for(int c=0; c<cS; c++){
                if(grid[r][c] == '1' && visited[r][c] == 0){
                    dfs(r,c,grid);
                    islandsNumber++;
                }
            }
        }
        return islandsNumber;


        
    }

    void dfs(int r, int c, const vector<vector<char>>& grid){

        if(r >= grid.size() || c>= grid[0].size() || r<0 || c<0 ||
            grid[r][c] == '0' || visited[r][c] == 1){
                return;
            }
        
        visited[r][c] = 1;

        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);

    }
};
