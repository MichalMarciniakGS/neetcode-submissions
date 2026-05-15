class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int colSize = grid[0].size();
        int rowSize = grid.size();
        vector<vector<char>> visited(rowSize, vector<char>(colSize, '0'));
        int islandsNum = 0;

        
        if(colSize == 0 || rowSize == 0){
            return 0;
        }

        for(int row=0; row < rowSize; row++){
            for(int col=0; col<colSize; col++){
                if(grid[row][col] == '1' && visited[row][col] == '0'){
                    dfs(grid,row,col,visited,islandsNum);
                    islandsNum++;
                }
            }
        }

        return islandsNum;


    }

    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<char>>& visited, int islandsNum){

        int colSize = grid[0].size();
        int rowSize = grid.size();

        if(row < 0 || col < 0 || row >= rowSize || col >= colSize || visited[row][col] == '1'
         || grid[row][col] == '0'){
            return;
         }

        //  grid[row][col] = '0';
         visited[row][col] = '1';

         dfs(grid, row+1, col, visited, islandsNum);
         dfs(grid, row-1, col, visited, islandsNum);
         dfs(grid, row, col+1, visited, islandsNum);
         dfs(grid, row, col-1, visited, islandsNum);

    }
};
