class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {

        int rowSize = grid.size();
        int colSize = grid[0].size();

        vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
        queue<pair<int,int>> queue;

        queue.push({0,0});
        visited[0][0] = 1;

        int length = 0;
        while(!queue.empty()){
            int initialQueueSize = queue.size();
            for(int j=0; j<initialQueueSize; j++){
                pair<int,int> coords = queue.front(); 
                int currRow = coords.first;
                int currCol = coords.second;
                queue.pop();

                if(currRow == rowSize-1 && currCol == colSize-1){
                    return length;
                }

                vector<vector<int>> allDir =
                {{currRow+1,currCol},{currRow-1,currCol},{currRow,currCol+1},{currRow,currCol-1}};

                for(int i=0; i<4; i++){
                    int nextRow = allDir[i][0];
                    int nextCol = allDir[i][1];
                    
                    if(nextRow < 0 || nextCol < 0 || nextRow >= rowSize || nextCol >= colSize
                    || grid[nextRow][nextCol] == 1 || visited[nextRow][nextCol] == 1){
                        continue;
                    }

                    queue.push({nextRow, nextCol});
                    visited[nextRow][nextCol] = 1;
                }
            }
            length++;
        }
        return -1;

    }
};
