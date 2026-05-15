class Solution {

    vector<pair<int,int>> allDirs = {{-1,0},{1,0},{0,-1},{0,1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rS = heights.size();
        int cS = heights[0].size();

        vector<vector<int>> res;

        vector<vector<bool>> pacificVec(rS, vector<bool>(cS, false));
        vector<vector<bool>> atlanticVec(rS, vector<bool>(cS, false));

        queue<pair<int,int>> pacificQ;
        queue<pair<int,int>> atlanticQ;

        for(int r=0; r<rS; r++){
            pacificQ.push({r,0});
            atlanticQ.push({r,cS-1});
        }

        for(int c=0; c<cS; c++){
            pacificQ.push({0,c});
            atlanticQ.push({rS-1,c});
        }

        helper(pacificQ, pacificVec, heights);
        helper(atlanticQ, atlanticVec, heights);

        for(int r=0; r<rS; r++){
            for(int c=0; c<cS; c++){
                if(pacificVec[r][c] == true && atlanticVec[r][c]){
                    res.push_back({r,c});
                }
            }
        }

        return res;
        
    }

    void helper(queue<pair<int,int>> q, vector<vector<bool>>& ocean, const vector<vector<int>>& heights){

        while(!q.empty()){
            auto [cR, cC] = q.front();
            q.pop();

            ocean[cR][cC] = true;

            for(auto [dR,dC] : allDirs){
                int nR = cR+dR;
                int nC = cC+dC;

                if(nR >= heights.size() || nC >= heights[0].size() || nR < 0 || nC < 0
                || ocean[nR][nC] == true || heights[nR][nC] < heights[cR][cC]){
                    continue;
                }

                q.push({nR,nC});
            }
        }

    }
};
