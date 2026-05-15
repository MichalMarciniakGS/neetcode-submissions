class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int res = 0;

        // 0 - not visited
        vector<vector<char>> visited(rowSize, vector<char>(colSize, '0'));


        for(int r=0; r<rowSize; r++){
            for(int c=0; c<colSize; c++){
                if(grid[r][c] != '0' && visited[r][c] == '0'){
                helper(r, c, grid, visited);
                res++;
                }
            }
        }

        return res;


    }

    int helper(int r, int c, const vector<vector<char>>& grid, vector<vector<char>>& visited){

        if(r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0 
            || grid[r][c] == '0' || visited[r][c] == '1'){
                return 0;
            }

        visited[r][c] = '1';

        helper(r+1,c,grid,visited);
        helper(r,c+1,grid,visited);
        helper(r-1,c,grid,visited);
        helper(r,c-1,grid,visited);

        return 1;     
    }
};
