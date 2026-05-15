class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int rMax = grid.size(); // to zmienilem bo najpierw mialem
        int cMax = grid[0].size(); // grid[0].size na rMax i
        int islandsNum = 0; // grid[0][0].size na cMax (bez sensu xD)
        int res = 0;
        vector<vector<char>> visited(rMax, vector<char>(cMax,'0'));

        for(int r=0; r<rMax; r++){
            for(int c=0; c<cMax; c++){
                if(grid[r][c] != '0' && visited[r][c] != '1'){ //ten warunek musiałem dodać
                islandsNum = helper(r,c,grid,visited); // zeby niesprawdzac niepotrzebnych pol
                res += islandsNum;
                }
            }
        }
        return res;

        
    }

    int helper(int r, int c, const vector<vector<char>>& grid, vector<vector<char>>& visited){

        int islands = 0;

        if(r >= grid.size() || c>= grid[0].size()
         || r < 0 || c < 0
         || grid[r][c] == '0' || visited[r][c] == '1'){
            return 0;
         }

        visited[r][c] = '1';


        helper(r+1,c,grid,visited);
        helper(r,c+1,grid,visited);
        helper(r-1,c,grid,visited);
        helper(r,c-1,grid,visited);

        return 1; // tu zmienilem z 'return islands' które było inkrementowane o 1
    }              // za kazdym razem
};
