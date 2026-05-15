class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rowSize = grid.size();
        int colSize = grid[0].size();
        int maxSize = 0;
        int area = 0;

        if(rowSize == 0 || colSize == 0){
            return 0;
        }

        vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));

        for(int row=0; row<rowSize; row++){
            for(int col=0; col<colSize; col++){
                if(grid[row][col] == 1 && visited[row][col] == 0){
                    area = dfs(grid, row, col, visited);
                    if(area > maxSize){
                        maxSize = area;
                    }
                }
            }
        }

        return maxSize;
        
    }

    int dfs(vector<vector<int>> grid, int row, int col, vector<vector<int>>& visited){

        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()
         || grid[row][col] == 0 || visited[row][col] == 1){
            return 0;
         }

        visited[row][col] = 1;
        int result = 1;

        result += dfs(grid, row+1, col, visited);
        result += dfs(grid, row-1, col, visited);
        result += dfs(grid, row, col+1, visited);
        result += dfs(grid, row, col-1, visited);

        return result;

    }
};
