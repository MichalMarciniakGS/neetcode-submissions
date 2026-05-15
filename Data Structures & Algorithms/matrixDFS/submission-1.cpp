class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {

        int rowSize = grid.size();
        int colSize = grid[0].size();
        vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));

        return dfs(grid, 0, 0, visited);

    }

    int dfs(vector<vector<int>> grid, int row, int col, vector<vector<int>>& visited){
        
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() 
        || grid[row][col] == 1 || visited[row][col] == 1){
            return 0;
        }

        if( row == grid.size()-1
        && col == grid[0].size()-1){
            return 1;
        }

        visited[row][col] = 1;

        int count = 0;
        count += dfs(grid, row+1, col, visited);
        count += dfs(grid, row-1, col, visited);
        count += dfs(grid, row, col+1, visited);
        count += dfs(grid, row, col-1, visited);

        visited[row][col] = 0;
        return count;
    }
};
