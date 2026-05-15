class Solution {

    vector<pair<int,int>> allDirs = {{1,0},{-1,0},{0,1},{0,-1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rS = heights.size();
        int cS = heights[0].size();

        queue<pair<int,int>> pacQ;
        queue<pair<int,int>> atlQ;

        vector<vector<bool>> pacV(rS, vector<bool>(cS, false));
        vector<vector<bool>> atlV(rS, vector<bool>(cS, false));

        vector<vector<int>> res;

        for(int r=0; r<rS; r++){
            pacQ.push({r,0});
            atlQ.push({r,cS-1});
        }

        for(int c=0; c<cS; c++){
            pacQ.push({0,c});
            atlQ.push({rS-1,c});
        }

        helper(heights, pacQ, pacV, res);
        helper(heights, atlQ, atlV, res);

        for(int r=0; r<rS; r++){
            for(int c=0; c<cS; c++){
                if(pacV[r][c] && atlV[r][c]){
                    res.push_back({r,c});
                }
            }
        }

        return res;

    }

    void helper(vector<vector<int>>& heights, queue<pair<int,int>>& q,
     vector<vector<bool>>& vec, vector<vector<int>>& res){

        while(!q.empty()){
            auto coords = q.front();
            q.pop();
            int r = coords.first;
            int c = coords.second;
            vec[r][c] = true; // jesli trafil wgl do kolejki, to na pewno jest true
            for(auto [dr,dc] : allDirs){
                int nr = r+dr;
                int nc = c+dc;
                if(nr >= heights.size() || nc >= heights[0].size() || nr < 0 || nc < 0 
                    || vec[nr][nc] == true || heights[r][c] > heights[nr][nc]){
                        continue;
                    }
                q.push({nr,nc});
            }
        }

     }
};
