class Solution {

    vector<pair<int,int>> allDirs = {{0,1},{1,0},{0,-1},{-1,0}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rS = heights.size();
        int cS = heights[0].size();

        vector<vector<int>> res;

        vector<vector<bool>> pac(rS, vector<bool>(cS,false));
        vector<vector<bool>> atl(rS, vector<bool>(cS,false));

        queue<pair<int,int>> pacQ, atlQ;

        for(int r=0; r<rS; r++){
            pacQ.push({r,0});
            atlQ.push({r,cS-1});    
        }

        for(int c=0; c<cS; c++){
            pacQ.push({0,c});
            atlQ.push({rS-1,c});
        }

        helper(pacQ, pac, heights);
        helper(atlQ, atl, heights);

        for(int r=0; r<rS; r++){
            for(int c=0; c<cS; c++){
                if(pac[r][c] == true && atl[r][c] == true){
                    res.push_back({r,c});
                }
            }
        }

        return res;
        
    }

            void helper(queue<pair<int,int>>& q, vector<vector<bool>>& ocean, const vector<vector<int>>& heights){

            while(!q.empty()){
                auto coords = q.front();
                int r = coords.first;
                int c = coords.second;
                q.pop();
                ocean[r][c] = true;

                for(auto [dr,dc] : allDirs){
                    int nr = r+dr;
                    int nc = c+dc;

                    if(nr<0 || nc<0 || nr>=heights.size() || nc>=heights[0].size()
                        || ocean[nr][nc] == true || heights[r][c] > heights[nr][nc]){
                            continue;
                        }
                    q.push({nr,nc});
                }


            }

        }
};
