class Solution {

    vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size(), cols = heights[0].size();

        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        queue<pair<int,int>> pacificQ, atlanticQ;
        vector<vector<int>> result;
        
        for(int c=0; c<cols; c++){
            pacificQ.push({0,c});
            atlanticQ.push({rows-1,c});
        }

        for(int r=0; r<rows; r++){
            pacificQ.push({r,0});
            atlanticQ.push({r,cols-1});
        }

        bfs(pacificQ, pac, heights);
        bfs(atlanticQ, atl, heights);

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(pac[r][c] && atl[r][c]){
                    result.push_back({r,c});
                }
            }
        }
        return result;
    }

    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            ocean[r][c] = true;

            for(auto [dr,dc] : dirs){
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= heights.size() || nr < 0 || nc >= heights[0].size() || nc < 0
                    || heights[nr][nc] < heights[r][c] || ocean[nr][nc] == true){
                        continue;
                    }
                q.push({nr,nc});
            }
        }
    }
};
