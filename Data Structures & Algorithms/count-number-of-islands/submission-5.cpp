class Solution {
    vector<vector<char>> visited;
public:
    int numIslands(vector<vector<char>>& grid) {

        int islandsNum = 0;
        int rowSize = grid.size();
        int colSize = grid[0].size();
        visited.assign(rowSize, vector<char>(colSize,'0')); // 0 - not visited

        for(int r=0; r<rowSize; r++){
            for(int c=0; c<colSize; c++){
                if(grid[r][c] == '1' && visited[r][c] == '0'){
                    helper(r,c,grid);
                    islandsNum++;
                }
            }
        }
        return islandsNum;

        
    }
    void helper(int r, int c,const vector<vector<char>>& grid){
        if(r >= grid.size() || c >= grid[0].size() || r<0 || c<0
         || grid[r][c] == '0' || visited[r][c] == '1'){
            return;
         }

         visited[r][c] = '1';

         helper(r+1,c,grid);
         helper(r,c+1,grid);
         helper(r-1,c,grid);
         helper(r,c-1,grid);
    }
};
