class Solution {

    vector<pair<int,int>> allDirs = {{1,0},{0,1},{-1,0},{0,-1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rS = heights.size();
        int cS = heights[0].size();

        queue<pair<int,int>> pacQ;
        queue<pair<int,int>> atlQ;

        vector<vector<bool>> pac(rS, vector<bool>(cS, false));
        vector<vector<bool>> atl(rS, vector<bool>(cS, false));

        vector<vector<int>> res;

        //Putting all cells that are at the start adjactent to pac or atl
        for(int r=0; r<rS; r++){
            pacQ.push({r,0});
            atlQ.push({r,cS-1});
        }
        for(int c=0; c<cS; c++){
            pacQ.push({0,c});
            atlQ.push({rS-1,c});
        }

        //Doing BFS's to determine results
        bfs(pacQ, pac, heights);
        bfs(atlQ, atl, heights);

        for(int r=0; r<rS; r++){
            for(int c=0; c<cS; c++){
                if(pac[r][c] == true && atl[r][c] == true){
                    res.push_back({r,c});
                }
            }
        }
        return res;


    }

    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& ocean, const vector<vector<int>> heights){

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            ocean[r][c] = true;
            for(auto [dr,dc] : allDirs){
                int nr = r+dr;
                int nc = c+dc;

                if(nr >= heights.size() || nc >= heights[0].size() || nr < 0 || nc < 0 
                 || ocean[nr][nc] == true || heights[r][c] > heights[nr][nc]){
                    continue;
                 }
                q.push({nr,nc});

            }
        }

    }
};
