class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        //collect all rotten fruits
        queue<pair<int,int>> rottenFruits;
        int freshFruits = 0;
        int time = 0;
        vector<pair<int,int>> allDirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    rottenFruits.push({i,j});
                }
                if(grid[i][j] == 1){
                    freshFruits++;
                }
            }
        }

        while(!rottenFruits.empty() && freshFruits > 0){
            int initialRottenFruits = rottenFruits.size();

            for(int i=0; i < initialRottenFruits; i++){
                auto rottenFruitPair = rottenFruits.front();
                int rfR = rottenFruitPair.first;
                int rfC = rottenFruitPair.second;
                rottenFruits.pop();
                
                for(auto dir : allDirs){
                    if(rfR+dir.first >= grid.size() || rfC+dir.second >= grid[0].size()
                    || rfR+dir.first < 0 || rfC+dir.second <0
                    || grid[rfR+dir.first][rfC+dir.second] != 1){
                        continue;
                    }
                    grid[rfR+dir.first][rfC+dir.second] = 2;
                    freshFruits--;
                    rottenFruits.push({rfR+dir.first,rfC+dir.second});
                }
            }
            time++;
        }
        
        if(freshFruits != 0){
            return -1;
        }else{
            return time;
        }




    }
};