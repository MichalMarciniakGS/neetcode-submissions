class Solution {

    vector<vector<int>> visited;

public:
    int uniquePaths(int m, int n) {
        
        visited.assign(m, vector<int>(n,0));

        int cr = 0;
        int cc = 0;
        
        return helper(cr,cc,m,n);

    }

    int helper(int cr, int cc, int m, int n){

        if(cr >= m || cc >= n){
            return 0;
        }

        if(visited[cr][cc] != 0){
            return visited[cr][cc];
        }

        if(cr == m-1 && cc == n-1){
            return 1;
        }

        visited[cr][cc] = helper(cr+1,cc,m,n) + helper(cr,cc+1,m,n);
        return visited[cr][cc];

    }
};
