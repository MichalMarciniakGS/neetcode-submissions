class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // find coords of rotten fruit / fruits
        // xxx

        // vector<pair<int,int>> rottenFruits;
        queue<pair<int,int>> rottenFruits;
        int fresh = 0;
        int time = 0;

        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c] == 2){
                    rottenFruits.push({r,c});
                }
                else if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!rottenFruits.empty() && fresh > 0){

            int initialRottenFruitsSize = rottenFruits.size();
            for(int i = 0; i<initialRottenFruitsSize; i++){
                pair<int,int> coords = rottenFruits.front();
                rottenFruits.pop();
                int r = coords.first;
                int c = coords.second;

                for(auto dir : dirs){
                    int newR = r + dir.first;
                    int newC = c + dir.second;

                    if(newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid[0].size()
                        || grid[newR][newC] != 1){
                            continue;
                        }
                    
                    rottenFruits.push({newR,newC});
                    grid[newR][newC] = 2;
                    fresh--;
                }
            }
            time++;

        }
        return fresh == 0 ? time : -1;




    }
};
