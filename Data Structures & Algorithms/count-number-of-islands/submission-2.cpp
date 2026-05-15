class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rowSize = grid.size();
        int colSize = grid[0].size();

        // unordered_map<int, pair<int,int>> visited;
        vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
        int maxSize = 0;
        int islands = 0;

        for(int r=0; r<rowSize; r++){
            for(int c=0; c<colSize; c++){
                if(grid[r][c] != '0' && visited[r][c] != 1){
                    int count = 0;
                    islands++;
                    dfs(r,c,grid,visited, count);
                    // maxSize = max(count, maxSize);
                }
            }
        }
        return islands;

    }

    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& visited,int& count){

        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0' 
         || visited[r][c] == 1){
            return;
         }

        // int count = 0;
        count++;
        visited[r][c] = 1;

        dfs(r+1,c,grid,visited, count);
        dfs(r-1,c,grid,visited, count);
        dfs(r,c+1,grid,visited, count);
        dfs(r,c-1,grid,visited, count);
        
        return;
    }
};
