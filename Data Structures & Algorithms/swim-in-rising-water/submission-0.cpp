class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int N = grid.size();
        vector<vector<int>> visited(N, vector<int>(N,-1));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

        minHeap.push({grid[0][0],0,0});
        visited[0][0] = 1;

        while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int t=curr[0], r=curr[1], c=curr[2];
            if(r == N-1 && c == N-1){
                return t;
            }
            for(const auto& dir : dirs){
                int neiR = r + dir[0], neiC = c + dir[1];
                if(neiR<0 || neiC<0 || neiR >= N || neiC >= N
                 || visited[neiR][neiC] != -1){
                    continue;
                 }
                 visited[neiR][neiC] = 1;
                 int maxT = max(t, grid[neiR][neiC]);
                 minHeap.push({maxT, neiR, neiC});
            }
        }
        return -1;

        
    }
};
