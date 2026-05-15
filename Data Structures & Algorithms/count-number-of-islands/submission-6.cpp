class Solution {

    vector<vector<char>> visited;

public:
    int numIslands(vector<vector<char>>& grid) {

        int rowSize = grid.size();
        int colSize = grid[0].size();
        int res = 0;
        visited.assign(rowSize, vector<char>(colSize,'0')); //0 - not visited

        for(int r=0; r<rowSize; r++){
            for(int c=0; c<colSize; c++){
                if(grid[r][c] != '0' && visited[r][c] != '1'){
                    res += helper(r,c,grid);
                }
            }
        }
        return res;
        
    }
    int helper(int r, int c, const vector<vector<char>>& grid){

        if(r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0 
            || grid[r][c] == '0' || visited[r][c] == '1'){
                return 0;
            }

        visited[r][c] = '1';

        helper(r+1,c,grid);
        helper(r,c+1,grid);
        helper(r-1,c,grid);
        helper(r,c-1,grid);

        return 1;

    }
};
