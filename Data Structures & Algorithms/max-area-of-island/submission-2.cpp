class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        if(grid.empty()){
            return 0;
        }

        int rowsSize = grid.size();
        int colsSize = grid[0].size();
        
        int maxSize = 0;
        vector<vector<int>> visited(rowsSize, vector<int>(colsSize, 0));

        for(int r=0; r<rowsSize; r++){
            for(int c=0; c<colsSize; c++){
                if(grid[r][c] == 1 && visited[r][c] == 0){
                    // int count = 0;
                    int count = dfs(r,c,grid,visited);
                    maxSize = max(count, maxSize);
                }
            }
        }

        return maxSize;

    }

    int dfs(int r, int c, vector<vector<int>> grid, vector<vector<int>>& visited){

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() 
         || grid[r][c] == 0 || visited[r][c] == 1){
            return 0;
        }

        int count = 1;
        visited[r][c] = 1;

        for(auto dir : dirs){
            count += dfs(r+dir.first, c+dir.second, grid, visited);
        }

        return count;

    }
};
